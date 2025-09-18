#User function Template for python3

class Solution:
    def generateBinaryStrings(self, n):
        ans = []
        def solve(i, s):
            if i == n:
                ans.append(s)
                return
            # Always add '0'
            solve(i + 1, s + '0')
            # Add '1' only if last char is not '1'
            if not s or s[-1] != '1':
                solve(i + 1, s + '1')
        solve(0, "")
        return ans
# Similar to 22. Generate Parentheses