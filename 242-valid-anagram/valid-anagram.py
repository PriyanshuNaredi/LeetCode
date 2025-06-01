class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # 1.
        # return sorted(s) == sorted(t)

        # 2.
        return Counter(s) == Counter(t)
        