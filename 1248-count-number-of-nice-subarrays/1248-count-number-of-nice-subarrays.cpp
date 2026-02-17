class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        int oddCount = 0;  
    // Track the number of odd numbers encountered so far.

        while (j < nums.size()) {
            if (nums[j] % 2 == 1) {
                count = 0;  
    // Reset count when encountering an odd number.
                oddCount++;
            }

            while (oddCount == k) {
                if (nums[i] % 2 == 1) {
                    oddCount--;  
    // Reduce oddCount when moving the left pointer.
                }
                i++;
                count++;
            }

            ans += count;  
    // Add the count to ans for all subarrays with k odd numbers.

            j++;
        }

        return ans;
    }
};