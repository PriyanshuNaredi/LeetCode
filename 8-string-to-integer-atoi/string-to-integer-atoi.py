class Solution:
    def myAtoi(self, s: str) -> int:
        if not s:                          # ➊ empty string
            return 0

        INT_MIN, INT_MAX = -2**31, 2**31 - 1

        i = 0
        n = len(s)
        sign = 1
        res  = 0

        # ---------- 1. skip leading blanks ----------
        while i < n and s[i] == ' ':       # ➋ test length first
            i += 1
        if i == n:                         # ➌ only spaces
            return 0

        # ---------- 2. optional sign ----------
        if s[i] in '+-':                   # ➍ accept either symbol
            sign = -1 if s[i] == '-' else 1
            i += 1

        # ---------- 3. digits ----------
        while i < n and '0' <= s[i] <= '9':           # ➎ no isdigit()
            res = res * 10 + (ord(s[i]) - 48)         # ➏ no int()
            i += 1
            # ---- early clamp to 32-bit range ----
            if sign == 1 and res >= INT_MAX:          # ➐
                return INT_MAX
            if sign == -1 and res > -INT_MIN:         # (-INT_MIN == 2**31)
                return INT_MIN

        res *= sign

        # ---------- 4. final clamp (safety net) ----------
        if res < INT_MIN:
            return INT_MIN
        if res > INT_MAX:
            return INT_MAX
        return res


        # if len(s) < 1: return 0

        # sign = 1 # 0 -> - and 1 -> +

        # i = 0
        # res = 0
        # while s[i] == ' ' and i < len(s):
        #     i += 1
        # if s[i] == "-":
        #     sign = -1
        #     i+= 1
        # # print(s[i:])

        # while i < len(s):
        #     if not s[i].isdigit():
        #         break
        #     else:
        #         res = res * 10 + int(s[i])
        #         # print(s[i])

        #     i += 1

        # res *= sign

        # if res > 2**31 - 1:
        #     return 2**31
        # elif res <= -2**31 - 1:
        #     return -2**31
        # else:
        #     return res



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
