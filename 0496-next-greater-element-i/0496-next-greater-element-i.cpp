// O(n + m)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> v;
/*
        // Compact loop 
        for(int i = nums2.size() - 1; i >= 0; i--){
            if(st.size() == 0)
                v.push_back(-1);
            else if(st.size()>0 && st.top() > nums2[i])
                v.push_back(st.top());
            else if(st.size()>0 and st.top() <= nums2[i]){
                while(st.size()>0 and st.top() <= nums2[i])
                    st.pop();
                if(st.size()==0)
                    v.push_back(-1);
                else
                    v.push_back(st.top());
            }
            st.push(nums2[i], i);
        }
*/
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            v[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        /*
        // used unordered map to prevent below o(n^2)
        for(i = 0; i<nums1.size(); i++){
            for(int j = 0; j<nums2.size(); j++){

            }
        }
        */
        vector<int> res;
        for (int num : nums1) {
            res.push_back(v[num]);
        }
        return res;
    }
};