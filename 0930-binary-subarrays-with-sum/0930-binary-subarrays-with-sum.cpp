class Solution {
public:
    int helper(vector<int>& nums, int goal) {

        if (goal < 0)
            return 0;
            
        int i = 0, j = 0;
        int ans = 0;
        int sum = 0;
        while (j < nums.size()) {
            sum += nums[j];

            if (sum > goal) {
                while (sum > goal and i < nums.size()) {
                    sum -= nums[i];
                    i++;
                }
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};