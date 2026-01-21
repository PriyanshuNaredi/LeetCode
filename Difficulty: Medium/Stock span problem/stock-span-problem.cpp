class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        vector<int> v;
        stack<pair<int,int>> st; // NGL, index of NGL
        
        for(int i =0; i< arr.size(); i++){
            if(st.size() == 0)
                v.push_back(-1);
            else if(st.size() > 0 and st.top().first > arr[i])
                v.push_back(st.top().second);
            else if(st.size() > 0 and st.top().first <= arr[i]){
                while (st.size() > 0 and st.top().first <= arr[i])
                    st.pop();
                if(st.size() == 0)
                    v.push_back(-1);
                else
                    v.push_back(st.top().second);
            }
            st.push({arr[i],i});
        }
        for (int i=0; i<arr.size(); i++){
            v[i] = i - v[i];
        }
        return v;
    }
};