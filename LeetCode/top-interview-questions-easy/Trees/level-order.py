
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        result = []
        if not root:
            return result
        queue = []
        result.append([root.val])
        queue.append(root)
        while queue:
            level = []
            size = len(queue)
            for x in range(size):
                front = queue.pop(0)
                if front.left:
                    level.append(front.left.val)
                    queue.append(front.left)
                if front.right:
                    level.append(front.right.val)
                    queue.append(front.right)
            if level:
                result.append(level)
        return result
