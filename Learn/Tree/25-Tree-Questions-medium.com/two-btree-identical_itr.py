
class Node(object):
    '''
    '''
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right

def isIdentical(x, y):
    '''
    x and y are instances of Node class
    '''
    if not x and not y:
        return True
    elif (x and not y) or (not x and y):
        return False

    st = [(x,y)]

    while len(st) > 0:
        nodes = st.pop(0)
        n1, n2 = nodes[0], nodes[1]

        if not (n1 and n2 and n1.key==n2.key):
            return False

        if n1.left and n2.left:
            st.append((n1.left, n2.left))
        elif n1.left or n2.left:
            return False

        if n1.right and n2.right:
            st.append((n1.right, n2.right))
        elif n1.right or n2.right:
            return False

    return True

def __doAllTestsPass():
    allTestsPassing = True
    # Start writing here.

    root1 = Node(1)
    root1.left = Node(2)
    root1.right = Node(3)
    root1.left.left = Node(4)
    root1.left.right = Node(5)
    root1.left.right.left = Node(8)
    root1.left.right.left.left = Node(9)
    root1.left.right.left.left.left = Node(10)
    root1.right.right = Node(7)

    root2 = Node(1)
    root2.left = Node(2)
    root2.right = Node(3)
    root2.left.left = Node(4)
    root2.left.right = Node(5)
    root2.left.right.left = Node(8)
    root2.left.right.left.left = Node(9)
    root2.left.right.left.left.left = Node(10)
    root2.right.right = Node(7)

    allTestsPassing &= isIdentical(root1, root2)==True

    return allTestsPassing

if __name__ == '__main__':
    if __doAllTestsPass():
        print('All Tests are Passing.')
    else:
        print('Failed for one or more tests.')

