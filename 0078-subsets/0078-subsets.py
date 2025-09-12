class Solution:
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

    def subbackTrackSol(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrack(start, path):
            res.append(path)
            for i in range(start, len(nums)):
                backtrack(i + 1, path + [nums[i]])
        backtrack(0, [])
        return res
