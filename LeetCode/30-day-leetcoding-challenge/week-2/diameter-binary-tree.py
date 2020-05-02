
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ''''''
    def height(self, node):
        if not node:
            return 0
        return max(self.height(node.left), self.height(node.right)) + 1

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        ld = self.diameterOfBinaryTree(root.left)
        rd = self.diameterOfBinaryTree(root.right)
        root_d = 1 + self.height(root.left) + self.height(root.right)
        root_d = root_d - 1 # Path length = Number of nodes - 1
        return max(max(ld, rd), root_d)
