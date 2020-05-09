
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.helper(root, root)

    def helper(self, root1: TreeNode, root2: TreeNode) -> bool:
        if root1 and root2 and root1.val == root2.val:
            return self.helper(root1.left, root2.right) and self.helper(root2.left, root1.right)
        if root1 == root2 == None:
            return True
        return False
