
from math import log

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n>0 and abs(log(n, 3)-round(log(n, 3))) < 1e-10

