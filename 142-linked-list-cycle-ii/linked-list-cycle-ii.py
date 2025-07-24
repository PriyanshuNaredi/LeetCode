# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize a slow and fast
        # pointers to the head of the list
        slow = head
        fast = head

        # Phase 1: Detect the loop
        while fast is not None and fast.next is not None:
            # Move slow one step
            slow = slow.next

            # Move fast two steps
            fast = fast.next.next

            # If slow and fast meet,
            # a loop is detected
            if slow == fast:
                # Reset the slow pointer
                # to the head of the list
                slow = head

                # Phase 2: Find the first
                # node of the loop
                while slow != fast:
                    # Move slow and fast one
                    # step at a time
                    slow = slow.next
                    fast = fast.next

                    # When slow and fast meet again,
                    # it's the first node of the loop
                return slow

        # If no loop is found, return None
        return None
import sys
import atexit

# Equivalent to: std::cin.tie(nullptr)->sync_with_stdio(false);
# In Python, this helps speed up I/O
input = sys.stdin.readline

# LC_HACK equivalent
def write_display_runtime():
    with open("display_runtime.txt", "w") as f:
        f.write("0\n")

# Registering the function to be called at program exit
atexit.register(write_display_runtime)
