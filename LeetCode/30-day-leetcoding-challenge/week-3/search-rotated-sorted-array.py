


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.binary_search(nums, 0, len(nums)-1, target)

    def binary_search(self, arr, l, h, k):
        if l > h:
            return -1
        m = (l+h)//2
        if arr[m] == k:
            return m
        if arr[l] <= arr[m]:
            if arr[l] <= k and k <= arr[m]:
                return self.binary_search(arr, l, m-1, k)
            return self.binary_search(arr, m+1, h, k)
        elif arr[m] <= k and k<= arr[h]:
            return self.binary_search(arr, m+1, h, k)
        return self.binary_search(arr, l, m-1, k)

