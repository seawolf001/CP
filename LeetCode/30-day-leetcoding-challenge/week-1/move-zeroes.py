


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        z = 0
        for i in range(size):
            if nums[i] != 0:
                nums[z] = nums[i]
                z += 1
        for i in range(z, size):
            nums[i] = 0

