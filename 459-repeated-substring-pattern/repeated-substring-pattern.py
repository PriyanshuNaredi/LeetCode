class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # # ---- build LPS ----
        lps = [0] * len(s)
        preLPS, i = 0, 1
        while i < len(s):
            # Case1 : if both matches than increment pointer and lps[i] = needle[preLPS]
            if s[i] == s[preLPS]:
                lps[i] = preLPS + 1
                i += 1
                preLPS += 1
            # Case3 : case2's check, to prevent preLPS going index out of bound
            elif preLPS == 0:
                lps[i] = 0
                i += 1
            # Case2 : if they don't matche then look in preLPS - 1, value in lps array
            else:
                preLPS = lps[preLPS - 1]
        # ---- optional debug: print LPS ----
        for val in lps:
            print(val)

        # ---- final pattern check ----
        k = lps[-1]                      # length of longest happy prefix
        return k != 0 and len(s) % (len(s) - k) == 0
