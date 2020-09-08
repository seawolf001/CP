

from collections import deque
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    """"""
    def __height(self, root):
        """"""
        if not root:
            return 0
        return 1 + max(self.__height(root.left), self.__height(root.right))

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        values = []
        if not root:
            return "[]"
        q = deque()
        h = self.__height(root)
        q.append((root,1, root.val))
        while len(q):
            f, l, v = q.popleft()
            values.append(str(v))
            if f and f.left:
                q.append((f.left, l+1, f.left.val))
            elif l<h:
                q.append((None, l+1, "null"))
            if f and f.right:
                q.append((f.right, l+1, f.right.val))
            elif l<h:
                q.append((None, l+1, "null"))
        ans = "[" + ",".join(values) + "]"
        print(ans)
        return ans

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if (not data) or (data == "[]"):
            return None

        def modified_int(x):
            """"""
            try:
                return int(x)
            except (ValueError, TypeError):
                return None

        data = list(map(modified_int, data[1:-1].split(",")))
        root = TreeNode(data.pop(0))
        q = deque()
        q.append(root)
        while data:
            if not q:
                break
            node = q.popleft()

            l = data.pop(0)
            if None != l:
                node.left = TreeNode(l)
                q.append(node.left)
            else:
                node.left = None

            r = data.pop(0)
            if None != r:
                node.right = TreeNode(r)
                q.append(node.right)
            else:
                node.right = None
        return root

# Your Codec object will be instantiated and called as such:
#  codec = Codec()
#  codec.deserialize(codec.serialize(root))


