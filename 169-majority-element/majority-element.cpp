class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* Better Sol
        map <int,int> mpp;
        for (int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for (auto it:mpp){
            if ( it.second > ( nums.size() / 2))
                return it.first;
        }

        return -1;
        */

        /* Optimal Sol */
        int cnt=0, el;

        for (int i = 0; i < nums.size(); i++){
            if (cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if ( nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        int cntt = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == el ){
                cntt++;
            }
        }

        if ( cntt > (nums.size() /2 )){
            return el;
        }


        return -1;
    }
};