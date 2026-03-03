class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndx = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxIndx < i)
                return false;
            maxIndx = max(maxIndx, i+nums[i]);
        }
        return true;
    }
};