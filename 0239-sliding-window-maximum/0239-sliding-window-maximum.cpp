class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        list<int> l;
        int i=0, j= 0;

        // edge case
        if (k>nums.size()) 
        {
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        }

        while(j < nums.size()){

            // j calc
            while( l.size() > 0 and l.back() < nums[j])
                l.pop_back();
            l.push_back(nums[j]);

            // widow size
            if(j-i+1 < k)
                j++;
            
            else if(j-i+1 == k){
                // ans calc
                ans.push_back(l.front());
                // i calc
                if(l.front() == nums[i]) 
                    l.pop_front();
                // window move
                i++;
                j++;
            }

        }

        return ans;
    }
};