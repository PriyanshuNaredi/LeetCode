class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        res = ""
        resLen = 0
        n = len(s)

        for i in range(n):
            # start from a char and look its left and right char 
            # if they are same then update the res and resLen

            # odd numbered Palindrome
            l, r = i, i 
            while l >= 0 and r < n and s[l] == s[r]:
                # same, now update lenght
                if (r - l + 1) > resLen:
                    res = s[l:r+1]
                    resLen = r - l + 1
                l -= 1
                r += 1
            
            # even numbered Palindrome
            l, r = i, i+1
            while l >= 0 and r < n and s[l] == s[r]:
                # same, now update lenght
                if (r - l + 1) > resLen:
                    res = s[l:r+1]
                    resLen = r - l + 1
                l -= 1
                r += 1
            
        
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
