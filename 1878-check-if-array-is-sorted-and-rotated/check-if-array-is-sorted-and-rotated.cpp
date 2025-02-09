class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            //count the number of times an element is greater than its next element
            if (nums[i] > nums[i + 1]) {
                count++;
                if (count > 1) {
                    return false;
                }
            }
        }
        // Check if the last element is smaller than the first element
        if (count == 1 && nums[0] < nums[nums.size() - 1]) {
            return false;
        }
        return true;
    }
};