class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // to get no of rotation that aren't complete one i.e back to original
        reverse(nums.begin(), nums.end()); // reverse the entire array
        reverse(nums.begin(), nums.begin() + k); // reverse the first k elements
        reverse(nums.begin() + k, nums.end()); // reverse the rest of the array
    }
};