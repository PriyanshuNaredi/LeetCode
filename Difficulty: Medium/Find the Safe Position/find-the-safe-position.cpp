class Solution {
    void solve(vector<int> v, int k, int index, int &ans){
        if(v.size() == 1){
            ans = v[0];
            return;
        }
        index = (index + k) % v.size(); // identify target 
        v.erase(v.begin() + index); // kill target and pass the sword
        solve(v, k, index, ans);
    }
  public:
    int safePos(int n, int k) {
        // code here
        k = k-1;
        vector<int> v;
        for (int i=0; i<n; i++){
            v.push_back(i+1);
        }
        int index = 0;
        int ans = -1;
        solve(v, k, index, ans);
        return ans;
    }
};
