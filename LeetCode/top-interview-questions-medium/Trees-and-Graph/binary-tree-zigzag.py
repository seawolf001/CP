
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque, defaultdict

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        q = deque([(root, 0)]) if root else []
        result = defaultdict(list)
        while q:
            node, level = q.popleft()
            result[level].append(node.val)
            if node.left: q.append((node.left, level+1))
            if node.right: q.append((node.right, level+1))
        return [result[level][::(1,-1)[level & 1]] for level in range(len(result))]


