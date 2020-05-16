



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:

    def lengths(self, h1:ListNode, h2: ListNode) -> (int, int):
        n1, n2 = 0, 0
        while h1 and h2:
            n1 += 1
            h1 = h1.next
            n2 += 1
            h2 = h2.next
        while h1:
            n1 += 1
            h1 = h1.next
        while h2:
            n2 += 1
            h2 = h2.next
        return n1, n2

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        len1, len2 = self.lengths(headA, headB)
        larger, smaller = None, None
        if len1 > len2:
            diff = len1 - len2
            larger = headA
            smaller = headB
        elif len2 > len1:
            diff = len2 - len1
            larger = headB
            smaller = headA
        else:
            diff = 0
            larger = headA
            smaller = headB
        while diff > 0:
            larger = larger.next
            diff -= 1
        while smaller != larger:
            smaller = smaller.next
            larger = larger.next
        return smaller

