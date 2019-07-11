
class Node:
    """
    Standard Node class to form any node given its key
    """
    def __init__(self, data):
        self.left=None
        self.right=None
        self.parent=None
        self.key=data

class Queue:
    """
    Queue implemented using list
    """
    def __init__(self):
        self.queue = []

    def push(self, key):
        self.queue.append(key)

    def pop(self):
        if not self.queue:
            raise Exception('queue is empty')
        return self.queue.pop(0)

    def front(self):
        if not self.queue:
            raise Exception('queue is empty')
        return self.queue[0]

    def size(self):
        return len(self.queue)

    def empty(self):
        return True if self.size() == 0 else False

def new_node(key):
    node = Node(key)
    node.left=None
    node.right=None
    node.parent=None
    return node

def insert(node, key):
    if not node:
        return new_node(key)
    if not isinstance(node, Node):
        raise Exception('invalid node type')
    if key < node.key:
        node.left=insert(node.left,key)
        node.left.parent=node
    else:
        node.right=insert(node.right,key)
        node.right.parent=node
    return node

def depth(node):
    if not isinstance(node, Node):
        raise Exception('invalid node type')
    d=-1
    while node:
        d+=1
        node=node.parent
    return d

def LCA(n1,n2):
    d1 = depth(n1)
    d2 = depth(n2)
    diff = d1-d2
    if diff<0:
        temp=n1
        n1=n2
        n2=temp
    while diff:
        diff-=1
        n1=n1.parent
    while n1 and n2:
        if n1==n2:
            return n1
        n1=n1.parent
        n2=n2.parent
    return None

def printLevelOrder(root):
    if not root:
        return None
    queue = Queue()
    queue.push(root)

    while not queue.empty():
        count = queue.size()
        while count>0:
            node = queue.front()
            print (str(node.key),end=' ')
            queue.pop()
            if node.left:
                queue.push(node.left)
            if node.right:
                queue.push(node.right)
            count-=1
        print ()

if __name__ == '__main__':
    try:
        root = None
        root = insert(root, 20)
        root = insert(root, 8)
        root = insert(root, 22)
        root = insert(root, 4)
        root = insert(root, 12)
        root = insert(root, 10)
        root = insert(root, 14)
        print ('******************\nPrinting the tree in level-order')
        printLevelOrder(root)
        print('*******************')
        n1=root.left.right.left
        n2=root.right
        lca = LCA(n1,n2)
        print ('LCA of %s and %s is %s' % (n1.key, n2.key, lca.key))
    except Exception as e:
        print (e)

