
class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, x):
        self.head = Node(x, self.head)

def reverse(head, k):
    prev = None
    c=0
    curr = head
    while curr and c < k:
        c += 1
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
    if next:
        head.next = reverse(next, k)
    return prev

def printList(head):
    print('Printing the LinkedList', end=': ')
    curr = head
    items = []
    while curr:
        print(curr.data, end=' ')
        curr = curr.next

def __doAllTestsPass():
    # Start writing here.
    tests = int(input())
    while tests > 0:
        llist = LinkedList()
        n = int(input())
        values = list(map(int, input().split()))[:n]
        for x in reversed(values):
            llist.push(x)
        k = int(input())
        _head = reverse(llist.head, k)
        printList(_head)
        tests -= 1

if __name__ == '__main__':
    __doAllTestsPass()
