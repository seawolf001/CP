
#  Definition for singly-linked list.
#  class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        c = 0
        ans = ListNode()
        while l1 or l2:
            s = c
            s += l1.val if l1 else 0
            s += l2.val if l2 else 0
            c = 1 if s >= 10 else 0
            s = s % 10 if s >= 10 else s
            ans.next = ListNode(val=s)
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if c > 0:
            ans.next = ListNode(val=c)
        return ans.next
