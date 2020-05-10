

class Solution:
    def romanToInt(self, s: str) -> int:
        values = dict(
            I=1,
            V=5,
            X=10,
            L=50,
            C=100,
            D=500,
            M=1000)
        ans = 0
        i = 0
        while i < len(s):
            c1 = values[s[i]]
            if i+1 == len(s):
                ans += c1
                break
            else:
                c2 = values[s[i+1]]
                if c1 >= c2:
                    ans += c1
                    i += 1
                else:
                    ans += c2-c1
                    i += 2
        return ans

