# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:

        head1 = headA
        head2 = headB

        st = set()
        while head1 != None:
            st.add(head1)
            head1 = head1.next
        while head2 != None:
            if head2 in st:
                return head2
            head2 = head2.next
        return None
        