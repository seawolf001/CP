

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashed = dict()
        for x in range(len(nums)):
            if target - nums[x] in hashed:
                return sorted([x, hashed[target-nums[x]]])
            hashed[nums[x]] = x
        return []

