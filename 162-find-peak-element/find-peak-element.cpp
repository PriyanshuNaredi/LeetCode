class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid - 1]) // INC CURVE
                low = mid + 1;
            else if (nums[mid] > nums[mid + 1]) // DEC CURVE
                high = mid - 1;
            else // EDGE CASE: LOCAL MINIMA PROBLEM HANDEL
                high = mid - 1;
        }
        return -1;
    }
};