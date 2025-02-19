class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int index = -1;
        // fiding index of dip <- to find the longest prefix
        for(int i = nums.size() -2; i >= 0; i--){
            if (nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        // if there was no dip then the given nums is the last permutation 
        // just reverse the nums
        if (index == -1 ){
            reverse(nums.begin(), nums.end());
            return;
        }
        // finding the smallest number which is greater than nums[index]
        for(int i = nums.size() - 1; i > index; i--){
            if (nums[i] > nums[index]){
                swap(nums[i] , nums[index]);
                break;
            }
        }

        // 
        reverse(nums.begin()+index+1, nums.end());

        
    }
};