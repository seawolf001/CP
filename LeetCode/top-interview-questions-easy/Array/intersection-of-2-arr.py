from collections import defaultdict

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hashed = defaultdict(int)
        for x in nums1:
            hashed[x] += 1
        result = []
        for x in nums2:
            if hashed[x] > 0:
                hashed[x] -= 1
                result.append(x)
        return result
