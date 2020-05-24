

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def kthSmallest(self, root: TreeNode, k: int) -> int:
        return kthSmallestMorrisInorder(root, k)

    def kthSmallestMorrisInorder(root, k):
        count=0
        curr = root
        kth_smallest = float('-inf')
        while curr:
            if not curr.left:
                count += 1
                if count==k:
                    kth_smallest = curr.val
                curr = curr.right
            else:
                pre = curr.left
                while pre.right and pre.right != curr:
                    pre = pre.right
                if not pre.right:
                    pre.right = curr
                    curr = curr.left
                else:
                    pre.right = None
                    count += 1
                    if count==k:
                        kth_smallest = curr.val
                    curr = curr.right
        return kth_smallest

