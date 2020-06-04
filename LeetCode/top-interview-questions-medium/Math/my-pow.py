
class Solution:
    def myPow(self, x: float, n: int) -> float:
        """
        """
        if n==0:
            return 1
        negative = True if n < 0 else False
        if negative:
            n = -1 * n
        ans = self.pow(x, n)
        if negative:
            ans = 1/ans
        return round(ans,5)

    def pow(self, x, n):
        if n==0:
            return 1
        elif n==1:
            return x
        temp = self.pow(x, n//2)
        if n % 2 == 0:
            return temp * temp
        else:
            return x * temp * temp

assert Solution().myPow(2.00000, 10)==1024.00000
assert Solution().myPow(2.10000, 3)==9.26100
assert Solution().myPow(2.00000, -2)==0.25000
