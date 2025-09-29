// User function template for C++
class Solution {
    void solve(int one, int zero, string op, vector<string> &ans, int n){
        
        if (n==0){
            ans.push_back(op);
            return;
        }
        solve(one+1, zero, op+'1', ans, n-1);
        if(one>zero){
        solve(one, zero+1, op+'0', ans, n-1);
        }
        
    }
  public:
    vector<string> NBitBinary(int n) {
        // Your code goes here
        int one = 0;
        int zero = 0;
        string op = "";
        vector<string> ans;
        solve(one, zero, op, ans, n);
        return ans;
    }
};