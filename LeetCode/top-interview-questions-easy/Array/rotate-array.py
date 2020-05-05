from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        if k > 0:
            self.reverse(nums, 0, n-1)
            self.reverse(nums, 0, k-1)
            self.reverse(nums, k, n-1)


    def reverse(self, arr: List[int], low:int, high:int) -> None:
        ''''''
        while low <= high:
            temp = arr[low]
            arr[low] = arr[high]
            arr[high] = temp
            low += 1
            high -= 1

if __name__ == '__main__':
    arr = [1,2,3,4,5,6,7]
    #  print(arr)
    k = 3
    sol = Solution()
    sol.rotate(arr, k)
    #  print(arr)
    assert arr == [5,6,7,1,2,3,4]
