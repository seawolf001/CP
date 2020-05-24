


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not (preorder or inorder):
            return None
        self.indexes = {value:count for count, value in enumerate(inorder)}
        self.INDEX=0
        return self.buildTree_recurr(preorder, inorder, 0, len(inorder)-1)

    def buildTree_recurr(self, preorder, inorder, s, e):
        if s > e: return None
        val = preorder[self.INDEX]
        self.INDEX += 1
        node = TreeNode(val)
        if s == e:
            return node
        idx = self.indexes[val]
        node.left = self.buildTree_recurr(preorder, inorder, s, idx-1)
        node.right = self.buildTree_recurr(preorder, inorder, idx+1, e)
        print(node.val)
        return node

