
from typing import List
from heapq import heappush as push, heappop as pop, heapify

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-1 * x for x in stones]
        heapify(stones)
        while True:
            currLen = len(stones)
            if currLen > 1:
                mx1 = -1 * pop(stones)
                mx2 = -1 * pop(stones)
                if mx1 != mx2:
                    push(stones, -1 * abs(mx1-mx2))
            elif currLen == 1:
                return -1 * stones[0]
            else:
                return 0

