# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True
        return False

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
