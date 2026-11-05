# Palindrome Check

def is_palindrome(s):
    s = "".join(ch.lower() for ch in s if ch.isalnum())
    return s == s[::-1]

if __name__ == "__main__":
    print(is_palindrome("madam"))  # True
    print(is_palindrome("hello"))  # False
