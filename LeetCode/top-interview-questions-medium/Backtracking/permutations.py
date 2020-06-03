from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans = []
        self.permute_backtrack(nums, 0, len(nums)-1, ans)
        return ans

    def permute_backtrack(self, nums, l, r, ans):
        if l==r:
            ans.append(nums[:])
        else:
            for x in range(l,r+1):
                nums[l], nums[x] = nums[x], nums[l]
                self.permute_backtrack(nums, l+1, r, ans)
                nums[l], nums[x] = nums[x], nums[l]

#  print(Solution().permute([1,2,3]))
