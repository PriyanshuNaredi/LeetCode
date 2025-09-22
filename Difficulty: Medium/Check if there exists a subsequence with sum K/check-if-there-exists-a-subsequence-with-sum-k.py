#User function Template for python3

class Solution:
    def checkSubsequenceSum(self, N, arr, K):
        def solve(idx, s):
            if s == K:
                return True
            if s > K or idx == N:
                return False
            
            # Include or exclude current element
            return solve(idx + 1, s + arr[idx]) or solve(idx + 1, s)

        return solve(0, 0)

