
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head:
            return head
        if n == 0:
            return 0
        f,s = head, head
        for x in range(n):
            if not s.next:
                if x == n-1:
                    head = head.next
                return head
            s = s.next
        while s.next != None:
            s = s.next
            f = f.next
        f.next = f.next.next
        return head
