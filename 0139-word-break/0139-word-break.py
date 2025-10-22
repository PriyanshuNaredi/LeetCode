class Solution:
    # O(N∗M∗K)
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n+1)
        dp[0] = True 
        # Single line code for above 3 lines : dp = [True] + [False] * len(s)

        for i in range(1, n+1):
            for w in wordDict:
                # start = current position - length of word in wordDict
                start = i - len(w)
                # check until start == 0 and s[start : i] == w
                if start >= 0 and dp[start] and s[start : i] == w:
                    dp[i] = True
                    break
        
        return dp[-1]

'''
                            Start until >= 0
   l,e,e,t,c,o,d,e
[T,F,F,F,F,F,F,F,F]
     i

start = 2 - 4(= length of leet)
= -2

start = 2 - 4(= length of code)
= -2
------------------------------------
   l,e,e,t,c,o,d,e
[T,F,F,F,F,F,F,F,F]
       i

start = 3 - 4(= length of leet)
= -1

start = 3 - 4(= length of code)
= -1
------------------------------------
   l,e,e,t,c,o,d,e
[T,F,F,F,F,F,F,F,F]
         i

start = 4 - 4(= length of leet)
= 0
→ True

                                 s[start : i] == w
if s[start:i] == word in wordDict
= s[0:4] = "leet" 
= "leet" == "leet"
= True

   l,e,e,t,c,o,d,e
[T,F,F,F,T,F,F,F,F]
         i   

'''