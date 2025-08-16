'''

class Node:
    def __init__(self, d):
        self.data=d
        self.next=None
        self.bottom=None
        
'''

class Solution:
    def flatten(self, root):
        ''' Time Complexity -> (n*m)*2 + (n*m)log(n*m) '''
        
        arr = []
        # store the LL in array
        while(root):
            t2 = root
            while(t2):
                arr.append(t2.data)
                t2 = t2.bottom
            root = root.next
        
        # sort the array 
        arr.sort()
        
        # create new falttend LL
        dummyNode = Node(-1)
        temp = dummyNode
        
        for i in arr:
            temp.bottom = Node(i)
            temp = temp.bottom
        
        return dummyNode.bottom
        
        
        
        
        
        