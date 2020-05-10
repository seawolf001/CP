

class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2: return 0
        prime = [True] * n
        prime[0] = prime[1] = False
        p = 2
        while p**2 < n:
            if prime[p]:
                for x in range(p*p, n, p):
                    prime[x] = False
            print(prime)
            p += 1
        return prime.count(True)

print(Solution().countPrimes(8))

