from threading import Lock

class Queue(object):
    """
    Queue class with the basic enqueue and dequeue functionalities implemented.
    """
    def __init__(self):
        self.lock = Lock()
        self.elements = []

    def empty(self):
        '''
        Check if the queue is empty at the current timestamp.
        '''
        return len(self.elements) == 0

    def enqueue(self, entry):
        '''
        Push an element at the rear end of the queue.
        '''
        self.lock.acquire()
        self.elements.append(entry)
        self.lock.release()

    def dequeue(self):
        '''
        Dequeue an element if the queue is not empty. Raise exception otherwise.
        '''
        try:
            self.lock.acquire()
            front = None
            if self.empty():
                raise Exception('\nCan not dequeue from an empty queue.')
            front = self.elements.pop(0)
            self.lock.release()
        except Exception as exc:
            self.lock.release()
            raise exc
        return front

    def size(self):
        '''
        Size of queue
        '''
        return len(self.elements)

    def printQueue(self):
        '''
        Print the queue
        '''
        print ('\nCurrently, Following are the elements in the queue : ')
        print (self.elements)

if __name__ == '__main__':
    queue = Queue()
    while(True):
        try:
            choice = input ('\nPlease, Choose one from below choices :\n'
                    '1. enqueue an element\n'
                    '2. dequeue the front element\n'
                    '3. Size of queue\n'
                    '4. exit\n\n')
            choice = str(choice)
            if choice == '1':
                entry = int(input('Enter the element : '))
                queue.enqueue(entry)
            elif choice == '2':
                print('DeQueued element is : ' + str(queue.dequeue()))
            elif choice == '3':
                print ('Number elements present in the queue are : ' + str(queue.size()))
            elif choice == '4':
                break
            else:
                print ('Invalid choice. Please opt for a valid one. Ex: 1 or 2 or ....\n')
            if not queue.empty():
                queue.printQueue()
        except Exception as exc:
            print (exc)

