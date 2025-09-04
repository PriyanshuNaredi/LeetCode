class Solution:
    # your task is to complete this function
    # function sort the stack such that top element is max
    # funciton should return nothing
    # s is a stack
    def Sorted(self, s):
        self.sort(s)
        
        
    def sort(self,s):
        if (len(s)==1):
            return 
        temp = s.pop()
        self.sort(s)
        self.insert(s,temp)
        
        
    def insert(self,s, temp):
        if(len(s)==0 or s[-1]<= temp):
            s.append(temp)
            return
        val = s.pop()
        self.insert(s,temp)
        s.append(val)