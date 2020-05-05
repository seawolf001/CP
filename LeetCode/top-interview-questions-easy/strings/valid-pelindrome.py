import string

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.translate(str.maketrans(' ', '', string.punctuation)).lower()
        return s == s[::-1]
