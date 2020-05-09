

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        #  return self.reverse_recurr(head)
        return self.reverse_itr(head)

    def reverse_recurr(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        rev = self.reverse_recurr(head.next)
        head.next.next = head
        head.next = None
        return rev

    def reverse_itr(self, head:ListNode) -> ListNode:
        prev = None
        curr = head
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev
