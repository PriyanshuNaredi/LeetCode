from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()  # sort so duplicates are adjacent
        
        def solve(idx, path):
            ans.append(path[:])  # add a copy of current subset
            for i in range(idx, len(nums)):
                # skip duplicates
                if i > idx and nums[i] == nums[i-1]:
                    continue
                path.append(nums[i])
                solve(i+1, path)
                path.pop()  # backtrack
        
        solve(0, [])
        return ans

        