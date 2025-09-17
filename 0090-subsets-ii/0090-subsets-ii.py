class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = set() # stores only one copy 
        nums.sort() # not required
        
        def solve(ip, op):
            if not ip:
                ans.add(tuple(op))  # store as tuple as list are not hashable in python
                return
            
            # exclude
            solve(ip[1:], op)
            
            # include
            solve(ip[1:], op + [ip[0]])
        
        solve(nums, [])
        
        # convert back to list of lists
        return [list(t) for t in ans]

"""
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        
        def solve(ip, op):
            if not ip:
                ans.append(op)
                return
            solve(ip[1:], op)          # exclude current element
            solve(ip[1:], op + [ip[0]]) # include current element
        
        solve(nums, [])
        return ans
"""
        