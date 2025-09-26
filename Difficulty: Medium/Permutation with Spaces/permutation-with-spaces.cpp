class Solution {
    void solve(string &op , vector<string>&ans , string &s , int i){
        //base case 
        if(i == s.size() ){
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        // take space and char
        op1.push_back(' ');
        op1.push_back(s[i]);
        solve(op1, ans,  s , i+1);
        
        // not take space , only char 
        op2.push_back(s[i]);
        solve(op2 , ans , s, i+1); // move forward
        
    }
  public:

    vector<string> permutation(string s) {
        // Code Here
        string op ="";
        
        op.push_back(s[0]);
        
        vector<string>ans;
        
        s.erase(s.begin() +0);
        
        solve(op , ans ,s,0);
        
        return ans;
    }
};