class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* Better Solution  */
        map<int,int> mpp;
        for (int i=0; i<nums.size(); i++){
            int curr = nums[i];
            int remain = target - curr;
            if ( mpp.find(remain) != mpp.end()){
                return  {mpp[remain],i};
            }
            mpp[curr] = i;
        }
        return {-1,-1};
    }
};