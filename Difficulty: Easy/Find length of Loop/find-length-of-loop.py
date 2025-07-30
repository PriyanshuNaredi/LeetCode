'''
class Node:
    def __init__(self, data): 
        self.data = data
        self.next = None
'''
class Solution:
    def lengthOfLoop(self, head):
        #code here
        slow = head
        fast = head
    
        # Step 1: Traverse the list to detect a loop
        while fast is not None and fast.next is not None:
            # Move slow one step
            slow = slow.next     
            # Move fast two steps
            fast = fast.next.next  
    
            # Step 2: If the slow and fast
            # pointers meet, there is a loop
            if slow == fast:
                # Initialize the loop length
                length = 1  
                 # Move fast one step
                fast = fast.next 
    
                # Step 4: Initialize a counter
                # and traverse using the fast pointer
                while slow != fast:
                    # Move fast one step
                    fast = fast.next  
                    # Increment the counter
                    length += 1  
    
                # Step 6: Return the 
                # length of the loop
                return length
    
        # Step 3: If the fast pointer
        # reaches the end, there is no loop
        return 0  