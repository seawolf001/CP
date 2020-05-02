

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = head
        fast = head
        n = 1
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            n += 2
        if n % 2 == 0:
            return slow.next
        return slow
