
class Solution:
    """
    """
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        if len(needle) > len(haystack):
            return -1

        for i in range(len(haystack) - len(needle) + 1):
            if needle == haystack[i:i+len(needle)]:
                return i
        return -1

if __name__ == '__main__':
    print(Solution().strStr("hello", "ll"))
    print(Solution().strStr("aaaaa", "bba"))
    print(Solution().strStr("mississippi", "issip"))
