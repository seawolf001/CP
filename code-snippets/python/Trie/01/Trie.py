

class Node(object):
    """
    """
    def __init__(self):
        self.children = [None] * 26
        self.end = False

class Trie(object):
    '''
    '''
    def __init__(self):
        """
        """
        self.root = Node()

    def insert(self, word):
        """
        """
        curr = self.root
        size = len(word)
        for counter in range(size):
            index = ord(word[counter]) - ord('a')
            if not curr.children[index]:
                curr.children[index] = Node()
            curr = curr.children[index]
        curr.end = True

    def search(self, q):
        """
        """
        curr = self.root
        size = len(q)
        for counter in range(size):
            index = ord(q[counter]) - ord('a')
            if not curr.children[index]:
                return False
            curr = curr.children[index]
        return curr and curr.end

if __name__ == "__main__":
    words = [
        "the",
        "a",
        "there",
        "answer",
        "any",
        "by",
        "their"
    ]

    trie = Trie()
    for word in words:
        trie.insert(word)

    query = [
        "the",
        "these",
        "their",
        "thaw"
    ]

    for q in query:
        print(trie.search(q))
