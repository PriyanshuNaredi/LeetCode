class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() - 1, n = nums.size();
        // Edge cases {for better execution saves iteration Not NECESSARY }:
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        
	    int mid=(s + e) / 2;
        while (s < e)
        {
            if(nums[mid] < nums[mid+1])
                    s=mid+1;
            else
                e = mid;
        
            mid = (s + e) / 2;
        }
        return s;
    }
};