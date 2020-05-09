

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        maxp, low = 0, prices[0]
        n = len(prices)
        for x in range(1,n):
            if prices[x] < low:
                low = prices[x]
            else:
                maxp = max(maxp, prices[i]-low)
        return maxp
