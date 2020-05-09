


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root, mini=float('-inf'), maxi=float('inf')):
        return True if not root else \
            mini < root.val < maxi \
            and self.isValidBST(root.left, mini, root.val) \
            and self.isValidBST(root.right, root.val, maxi)

