
class Node(object):
    '''
    '''
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def __repr__(self):
        return repr(self.data)

class LL(object):
    '''
    '''
    def __init__(self, head=None):
        self.head = head

    def __repr__(self):
        nodes = []
        curr = self.head
        while curr:
            nodes.append(repr(curr))
            curr = curr.next
        return '[' + ' '.join(nodes) + ']'


    def push(self, data):
        node = Node(data, next=self.head)
        self.head = node

    def detectLoop(self):
        slow = self.head
        fast = self.head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

    def detectAndRemove(self):
        if (not self.head) or (not self.head.next):
            return
        slow = fast = self.head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        if slow == fast:
            slow = self.head
            while slow.next != fast.next:
                slow = slow.next
                fast = fast.next
            fast.next=None

def main():
    allTestsPassing = True
    ll = LL()
    ll.push(20)
    ll.push(4)
    ll.push(15)
    ll.push(10)

    print(repr(ll))
    allTestsPassing &= ll.detectLoop() == False
    ll.head.next.next.next.next = ll.head
    allTestsPassing &= ll.detectLoop() == True
    ll.detectAndRemove()
    allTestsPassing &= ll.detectLoop() == False

    ll = LL()
    ll.push(50)
    ll.push(20)
    ll.push(15)
    ll.push(4)
    ll.push(10)

    print(repr(ll))
    allTestsPassing &= ll.detectLoop() == False
    ll.head.next.next.next.next.next = ll.head
    allTestsPassing &= ll.detectLoop() == True
    ll.detectAndRemove()
    allTestsPassing &= ll.detectLoop() == False

    if allTestsPassing:
        print('All tests are passing')
    else:
        print('Did not pass all the tests.')

if __name__ == '__main__':
    main()

