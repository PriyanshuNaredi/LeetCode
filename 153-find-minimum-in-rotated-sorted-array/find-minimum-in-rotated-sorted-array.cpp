class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0, high = nums.size() - 1, ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;
            // check if the right half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]); 
                // directly compare ans with a[l] as this half is alredy sorted 
                low = mid + 1;
            } else { // check in the left sorted half
                ans = min(ans, nums[mid]);
                // directly compare ans with a[l] as this half is alredy sorted 
                high = mid - 1;
            }
        }

        return ans;
    }
};