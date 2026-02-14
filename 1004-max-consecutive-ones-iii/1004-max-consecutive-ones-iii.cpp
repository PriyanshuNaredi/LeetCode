class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int zeros = 0;  // Count zeros in current window
        int result = 0;

        while(j < nums.size()){
            // Expand window
            if(nums[j] == 0){
                zeros++;
            }
            
            // Shrink window if we have too many zeros
            while(zeros > k){
                if(nums[i] == 0){
                    zeros--;
                }
                i++;
            }
            
            // Update result with current window size
            result = max(result, j - i + 1);
            j++;
        }
         
        return result;
    }
};