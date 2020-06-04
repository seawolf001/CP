
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import Counter
        most_frequent = Counter(nums).most_common(k)
        return [x[0] for x in most_frequent]

