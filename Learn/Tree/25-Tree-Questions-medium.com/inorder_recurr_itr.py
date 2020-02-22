from collections import deque

class Node(object):
    """
    """
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right

class Tree(object):
    """
    """
    def __init__(self, node=None):
        """
        """
        self.root = node

    def insert(self, data):
        """
        """
        new_node = Node(data)

        x = self.root
        y = None

        if not x:
            self.root = x = new_node
            return

        while x:
            y = x
            if x.key >= data:
                x = x.left
            else:
                x = x.right

        if not y:
            y = new_node
        elif data < y.key:
            y.left = new_node
        else:
            y.right = new_node

    def InOrder_recurr(self, node, order=None):
        """
        """
        if order is None:
            order = []
        if not node:
            return
        self.InOrder_recurr(node.left, order)
        order.append(node.key)
        self.InOrder_recurr(node.right, order)

    def InOrder(self):
        """
        Returns inroder traversal in a list
        """
        order = []
        self.InOrder_recurr(self.root, order)
        return order

    def InOrderIter(self):
        """
        """
        order = []
        if not self.root:
            return order

        curr = self.root
        stack = deque()

        while len(stack)!=0 or curr:
            if curr:
                stack.append(curr)
                curr = curr.left
            else:
                curr = stack[-1]
                stack.pop()
                order.append(curr.key)
                curr = curr.right
        return order

def __doAllTestsPass():
    allTestsPassing = True
    # Start writing here.
    root = Tree(Node(50))
    root.insert(30)
    root.insert(20)
    root.insert(40)
    root.insert(70)
    root.insert(60)
    root.insert(80)

    allTestsPassing &= root.InOrder() == [20, 30, 40, 50, 60, 70, 80]
    allTestsPassing &= root.InOrderIter() == [20, 30, 40, 50, 60, 70, 80]

    return allTestsPassing

if __name__ == '__main__':
    if __doAllTestsPass():
        print('All Tests are Passing.')
    else:
        print('Failed for one or more tests.')

