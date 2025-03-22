class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = nums.size() - 3; i >= 0; i--){
            // as we have sort the nums it means the longest
            // 3 sides are at the last

            // so knowing the triangle property that the sum
            // of any two sides must be greater than the other
            // remaining one side, if this property holds for
            // last 3 elements just return their sum as the 
            // max 3 sides will always be at last bcz we
            // have sort the nums
            
            if(nums[i] + nums[i+1] > nums[i+2]){
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        return 0;
    }
};