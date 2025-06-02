class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        # LPS (L Preffix Suffix)
        lps = [0] * len(needle)
        preLPS, i = 0, 1
        while i < len(needle):
            # Case1 : if both matches than increment pointer and lps[i] = needle[preLPS]
            if needle[i] == needle[preLPS]:
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

        # KMP
        i, j = 0, 0
        while i < len(haystack):
            # Case1 : both value are same increment ptrs
            if haystack[i] == needle[j]:
                i, j = i + 1, j + 1
            # Case3 : prevent j and increment i so that while loop terminates
            elif j == 0:
                i += 1
            # case2 : if the value are not same then update j = lps[j-1]
            else:
                j = lps[j - 1]
            # Case4 : if the needle str matches with haystack and j reaches the end then return ans
            if j == len(needle):
                return i - len(needle)
        
        return -1
