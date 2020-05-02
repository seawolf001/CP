from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        results = []
        mapped = defaultdict(list)
        for word in strs:
            mapped["".join(sorted(word))].append(word)
        return list(mapped.values())

