
#TODO taking a lot of time. Need to think again and optimize

class Solution:
    def threeSum(self, nums):
        nums.sort()
        i, N, result = 0, len(nums), []
        while i < N - 2:
            j, k = i + 1, N - 1
            while j < k:
                Sum = nums[i] + nums[j] + nums[k]
                if not Sum:
                    result.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j + 1]: j += 1
                    j += 1
                    while j < k and nums[k] == nums[k - 1]: k -= 1
                    k -= 1
                elif Sum < 0:
                    while j < k and nums[j] == nums[j + 1]: j += 1
                    j += 1
                else:
                    while j < k and nums[k] == nums[k - 1]: k -= 1
                    k -= 1
            while i < N - 2 and nums[i] == nums[i + 1]: i += 1
            i += 1
        return result


