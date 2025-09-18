class Solution:
    def validStrings(self, n: int) -> List[str]:
        ans = []

        def solve(ip, op):
            if ip == n:
                ans.append(op)
                return
                
            solve(ip + 1, op + "1")

            if not op or op[-1] != "0":
                solve(ip + 1, op + "0")

        solve(0, "")
        return ans
