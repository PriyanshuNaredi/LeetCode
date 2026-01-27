class Solution:

    def subArrMin(self,nums):
        def findNSE(nums):
            n = len(nums)
            st = []
            nsei = []
            for i in range(n-1,-1,-1):
                while st and nums[st[-1]]>=nums[i]:
                    st.pop()
                if st:
                    nsei.append(st[-1])
                else:
                    nsei.append(n)
                st.append(i)
            return nsei[::-1]

        def findPSE(nums):
            n = len(nums)
            psei = []
            st = []
            for i in range(n):
                while st and nums[st[-1]] > nums[i]:
                    st.pop()
                if st:
                    psei.append(st[-1])
                else:
                    psei.append(-1)
                st.append(i)
            return psei
            
        n = len(nums)
        nsei = findNSE(nums)
        psei = findPSE(nums)
        sums = 0
        for i in range(n):
            left = i - psei[i]
            right = nsei[i] - i
            sums += left*right*nums[i]
        return sums
    
    def subArrMax(self,nums):
        def findNGE(nums):
            n = len(nums)
            st = []
            ngei = []
            for i in range(n-1,-1,-1):
                while st and nums[st[-1]]<nums[i]:
                    st.pop()
                if st:
                    ngei.append(st[-1])
                else:
                    ngei.append(n)
                st.append(i)
            return ngei[::-1]
        
        def findPGE(nums):
            n = len(nums)
            pgei = []
            st = []
            for i in range(n):
                while st and nums[st[-1]]<=nums[i]:
                    st.pop()
                if st:
                    pgei.append(st[-1])
                else:
                    pgei.append(-1)
                st.append(i)
            return pgei

        n = len(nums)
        ngei = findNGE(nums)
        pgei = findPGE(nums)
        sums = 0
        for i in range(n):
            left = i - pgei[i]
            right = ngei[i] - i
            sums += left*right*nums[i]
        return sums



    def subArrayRanges(self, nums: List[int]) -> int:

        smallestSum = self.subArrMin(nums)
        largestSum = self.subArrMax(nums)
        
        return largestSum - smallestSum

         