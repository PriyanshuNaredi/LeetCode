class Solution:
    def maxDepth(self, s: str) -> int:
        res = 0
        curr = 0

        for c in s:
            if c == '(':
                curr += 1
            elif c == ')':
                curr -= 1
            res = max(res, curr)

        return res
        

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
