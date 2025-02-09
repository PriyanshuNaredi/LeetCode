class Solution {
public:
/*For Right Rotation  
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // to get no of rotation that aren't complete one i.e back to original
        reverse(nums.begin(), nums.end()); // reverse the entire array
        reverse(nums.begin(), nums.begin() + k); // reverse the first k elements
        reverse(nums.begin() + k, nums.end()); // reverse the rest of the array
    }
/*
For Left Rotation 
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [4,5,6,7,1,2,3,]
*/
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // to get no of rotation that aren't complete one i.e back to original
        reverse(nums.begin(), nums.begin() + k); // reverse the first k elements
        reverse(nums.begin() + k, nums.end()); // reverse the rest of the array
        reverse(nums.begin(), nums.end()); // reverse the entire array
    }
};
