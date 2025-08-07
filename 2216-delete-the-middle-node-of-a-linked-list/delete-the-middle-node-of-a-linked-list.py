# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head.next is None:
            return None

        temp = head
        n = 0
        while temp is not None:
            n += 1
            temp = temp.next

        res = n // 2

        temp = head

        while temp is not None:
            res -= 1
            if res == 0 :
                middle = temp.next
                temp.next = temp.next.next
                break
            temp = temp.next
        
        return head

        