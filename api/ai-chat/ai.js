// Vercel serverless function: POST /api/ai-chat/ai
// Powers the Rival AI Mentor page (chat repo index.html), which sends
// { message, history: [{ role, text }] } and expects { reply } back.
// Uses the Groq free tier (llama-3.3-70b-versatile) via GROQ_API_KEY.
const GROQ_URL = 'https://api.groq.com/openai/v1/chat/completions';
const MODEL = 'llama-3.3-70b-versatile';
const DEFAULT_SYSTEM =
  'You are Rival AI Mentor, a friendly and helpful mentor for hackathon students. Answer clearly and practically. Reply in the same language the user writes in (English or Hinglish).';

const cors = (res) => {
  res.setHeader('Access-Control-Allow-Origin', '*');
  res.setHeader('Access-Control-Allow-Methods', 'POST, OPTIONS');
  res.setHeader('Access-Control-Allow-Headers', 'Content-Type');
};

module.exports = async (req, res) => {
  cors(res);
  if (req.method === 'OPTIONS') return res.status(200).end();
  if (req.method !== 'POST') return res.status(405).json({ ok: false, message: 'Method not allowed.' });

  const apiKey = process.env.GROQ_API_KEY;
  if (!apiKey) {
    return res.status(503).json({ ok: false, message: 'AI is not configured yet. Set GROQ_API_KEY.' });
  }

  const { message, history } = req.body || {};
  if (!message || typeof message !== 'string' || !message.trim()) {
    return res.status(400).json({ ok: false, message: 'Message is required.' });
  }

  const messages = [];
  let hasSystem = false;
  if (Array.isArray(history)) {
    for (const item of history.slice(-10)) {
      if (!item || typeof item.text !== 'string') continue;
      const role = ['system', 'user', 'assistant'].includes(item.role) ? item.role : 'user';
      if (role === 'system') hasSystem = true;
      messages.push({ role, content: item.text.slice(0, 4000) });
    }
  }
  if (!hasSystem) messages.unshift({ role: 'system', content: DEFAULT_SYSTEM });
  messages.push({ role: 'user', content: message.slice(0, 4000) });

  try {
    const groqRes = await fetch(GROQ_URL, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        Authorization: `Bearer ${apiKey}`,
      },
      body: JSON.stringify({
        model: MODEL,
        messages,
        temperature: 0.7,
        max_tokens: 1024,
      }),
    });

    const data = await groqRes.json().catch(() => ({}));
    if (!groqRes.ok) {
      const detail = data?.error?.message || `Groq API error (HTTP ${groqRes.status}).`;
      return res.status(502).json({ ok: false, message: detail });
    }

    const reply = data?.choices?.[0]?.message?.content?.trim();
    if (!reply) {
      return res.status(502).json({ ok: false, message: 'Empty reply from AI.' });
    }
    return res.json({ reply });
  } catch (err) {
    return res.status(502).json({ ok: false, message: `Could not reach the AI service: ${err.message}` });
  }
};
