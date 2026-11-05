# Rival AI Mentor — ChatGPT-style Chatbot

A polished, ChatGPT-like chat interface that talks to its own **/api/ai-chat/ai** endpoint
The app is deployed by the Vercel project "chat" at https://chat-abhi-f4ad.vercel.app, and the endpoint runs on Groq (model `openai/gpt-oss-120b`) using a `GROQ_API_KEY` environment variable.

The frontend is a **single HTML file** — no build step, no npm install — plus a Vercel serverless function in `api/ai-chat/ai.js` that proxies chat requests to Groq.

## ✨ Features
**Chat experience**
- ChatGPT-style layout (sidebar + centered conversation, avatars, welcome screen with suggestion cards)
- Typewriter **streaming** replies (speed configurable: Fast / Normal / Slow)
- **Regenerate** response, **Edit & resend**, **Retry** on errors, **Stop** generation
- Rich **markdown**: headings, lists, tables, blockquotes, links
- **Syntax-highlighted** code blocks (highlight.js) with per-block **Copy**
- "Scroll to bottom" button, smooth animations

**Chat management**
- **Multiple sessions** saved in your browser (localStorage)
- **Pin**, **Rename**, **Delete**, per-chat **Export (.md)**
- **Full-text search** across all chats
- **Import / Export all** chats as a JSON backup

**Input & accessibility**
- 🎤 **Voice input** (speech-to-text), 🔊 **Text-to-speech** (per message + auto-speak toggle)
- Optional **sound** on reply
- **Keyboard shortcuts**: `Ctrl/⌘+K` new chat · `Ctrl/⌘+/` focus input · `Ctrl/⌘+B` toggle sidebar · `↑` edit last · `Esc` stop
- Auto-growing input box, 4000-char support

**Customization**
- **System prompt / persona** editor (sent as a `system` history turn)
- **History turns** slider (how many past turns to send for context)
- 🌓 **Dark / Light** theme toggle
- Configurable **API Base URL** and **endpoint path**
- Live **connection status** dot + 🔌 Test button

## 🚀 Run it
The live deployment is https://chat-abhi-f4ad.vercel.app (Vercel project "chat"). To run it locally, no install is needed, but serve it over HTTP (voice/clipboard need a real origin):

```bash
cd chatbot
# Python 3
python -m http.server 5500
```
Open **http://localhost:5500**

> You can also just double-click `index.html`, but some features (mic) work best over `http://`.

## 🔌 Connect your API
Click the model name (top bar) or **⚙️ Settings & persona** and set:
- **API Base URL** — defaults to `https://chat-abhi-f4ad.vercel.app`; change it only if you run your own server
- **Endpoint path** — defaults to `/api/ai-chat/ai`
- Optionally a **system prompt** to shape the AI's personality

The app sends:
```json
{ "message": "your text", "history": [ { "role": "user|assistant|system", "text": "..." } ] }
```
and reads the **`reply`** string field from the JSON response — matching the `/api/ai-chat/ai` contract.

## 📝 Notes
- The Vercel deployment requires `GROQ_API_KEY` set as an environment variable in the Vercel project "chat".
- The frontend and the API are served from the same Vercel deployment, so no separate server or CORS setup is needed.
- Voice input & TTS depend on the browser (Chrome/Edge recommended).
