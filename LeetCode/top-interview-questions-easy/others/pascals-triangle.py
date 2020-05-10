from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        for x in range(1,numRows):
            curr = [1] * (x+1)
            prev = ans[-1]
            for i in range(1,len(prev)):
                curr[i] = prev[i]+prev[i-1]
            ans.append(curr)
        return ans
