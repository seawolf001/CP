

class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        elif n == 2:
            return "11"
        curr = "11"
        for x in range(3, n+1):
            count = 1
            temp = ""
            curr += "$"
            L = len(curr)
            for j in range(1, L):
                if curr[j] != curr[j-1]:
                    temp += str(count) + curr[j-1]
                    count = 1
                else:
                    count += 1
            curr = temp
        return curr

print(Solution().countAndSay(4))
