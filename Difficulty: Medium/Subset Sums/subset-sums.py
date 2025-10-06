class Solution:
	def subsetSums(self, arr):
		# code here
		ans = []
		
		def solve(index, sum):
		    if index == len(arr):
		        ans.append(sum)
		        return
		    solve(index+1, sum) # exclude
		    solve(index+1, sum + arr[index]) # include 

        solve(index = 0, sum = 0)
        # ans.sort()
        return ans