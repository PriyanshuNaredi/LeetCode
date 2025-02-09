class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = -1;
        // storing 1st index
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 0){
                zeroIndex = i;
                break;
            }
        }
        if (zeroIndex == -1) return ;

        // swapping zeroIndex with non-zeroIndex
        for (int i = zeroIndex+1; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i],nums[zeroIndex]);
                zeroIndex++;
            }
        }
    }
};