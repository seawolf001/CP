from typing import List

class Solution:
    def maxProfit(self, price: List[int]) -> int:
        maxp = 0
        i = 0
        n = len(price)
        while i < (n-1):
            while (i < n-1) and (price[i] >= price[i+1]):
                i += 1
            if i == n-1:
                break
            b = price[i]
            #  print("BUY on %s" % i)
            i += 1
            while (i < n) and (price[i] >= price[i-1]):
                i += 1
            s = price[i-1]
            #  print("SELL on %s" % (i-1))
            maxp += s-b
        return maxp
