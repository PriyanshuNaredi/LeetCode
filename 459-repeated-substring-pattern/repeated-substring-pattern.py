class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # ---- build LPS ----
        lps = [0] * len(s)
        preLPS, i = 0, 1                 # preLPS = length of current prefix-match

        while i < len(s):
            if s[i] == s[preLPS]:        # Case 1: characters match → extend prefix
                preLPS += 1
                lps[i] = preLPS
                i += 1
            elif preLPS:                 # Case 2: mismatch → fall back
                preLPS = lps[preLPS - 1]
            else:                        # Case 3: preLPS == 0 → no prefix to fall back to
                lps[i] = 0
                i += 1

        # ---- optional debug: print LPS ----
        for val in lps:
            print(val)

        # ---- final pattern check ----
        k = lps[-1]                      # length of longest happy prefix
        return k != 0 and len(s) % (len(s) - k) == 0
