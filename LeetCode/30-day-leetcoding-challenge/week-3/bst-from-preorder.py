from typing import List

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        return self.bstFromPreorder2_n_square(preorder, 0, len(preorder)-1, len(preorder))
        #  self.preidx = 0
        #  return self.bstFromPreorder_order_n(preorder, preorder[self.preidx], float('-inf'), float('inf'), len(preorder))

    def bstFromPreorder_order_n(self, preorder: List[int], key: int, MIN: int, MAX: int, n: int) -> TreeNode:
        if self.preidx >= n:
            return None
        root = None
        if MIN < key and key < MAX:
            root = TreeNode(key)
            self.preidx += 1
            if  self.preidx < n:
                root.left = self.bstFromPreorder_order_n(preorder, preorder[self.preidx], MIN, key, n)
            if self.preidx < n:
                root.right = self.bstFromPreorder_order_n(preorder, preorder[self.preidx], key, MAX, n)
        return root

    def bstFromPreorder2_n_square(self, preorder: List[int], l: int, h: int, n: int) -> TreeNode:
        if n == 0 or l > h or l >= n or h >= n:
            return None
        root = TreeNode(preorder[l])
        if l == h:
            return root
        x = float('-inf')
        for i in range(l+1, h+1):
            if preorder[i] > root.val:
                x = i-1
                break
        if x == float('-inf'):
            root.left = self.bstFromPreorder2_n_square(preorder, l+1, h, n)
        else:
            root.left = self.bstFromPreorder2_n_square(preorder, l+1, x, n)
            root.right = self.bstFromPreorder2_n_square(preorder, x+1, h, n)
        return root
