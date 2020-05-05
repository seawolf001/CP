
class Solution:

    def removeDuplicates(self, nums:List[int]) -> int:
        i = 0
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        return i+1

    #  def removeDuplicates(self, nums: List[int]) -> int:
    #      if not nums:
    #          return 0
    #      L = len(nums)
    #      count = L
    #      last = nums[0]
    #      for x in range(1, L):
    #          if nums[x] == last:
    #              nums[x] = float('-inf')
    #              count -= 1
    #          else:
    #              last = nums[x]
    #      j = -1
    #      for x in range(L):
    #          if nums[x] != float('-inf'):
    #              j += 1
    #              nums[j] = nums[x]
    #      return count




