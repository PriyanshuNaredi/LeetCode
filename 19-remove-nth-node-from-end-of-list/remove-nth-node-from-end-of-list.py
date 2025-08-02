# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    
        prev = None
        curr = head
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        return prev

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        head = self.reverseList(head)
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        curr = head
        for _ in range(n - 1):
            prev = curr
            curr = curr.next
        if curr:
            prev.next = curr.next
        return self.reverseList(dummy.next)
