class Solution {
public:
int binarySearchR(vector<int>& nums, int low, int high, int target) {
    //Base case.
    if (low > high) return -1; 
    int mid = (low + high) / 2;

    if (nums[mid] == target) return mid;
    // right side of mid
    else if (target > nums[mid])
        return binarySearchR(nums, mid + 1, high, target);
    // left side of mid
    return binarySearchR(nums, low, mid - 1, target);
}
int binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        // return binarySearch(nums, target);
        return binarySearchR(nums, 0, nums.size()-1, target);
    }
};