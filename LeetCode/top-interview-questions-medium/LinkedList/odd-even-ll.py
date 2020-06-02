

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        c, curr = 1, head
        even_head = head.next
        while curr:
            next = curr.next
            if next:
                curr.next = next.next
                curr = next
            else:
                curr.next = even_head
                break
        return head
