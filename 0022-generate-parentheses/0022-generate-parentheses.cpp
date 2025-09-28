class Solution {
    void solve(int open, int close, string op, vector<string> &ans){
        if(open == 0 and close == 0){
            ans.push_back(op);
            return;
        }
        // this choice is always there until we are out of open
        if (open != 0){
            string op1 = op;
            op1.push_back('(');
            solve(open-1, close, op1, ans);
        }
        // This is only present if close>open bcoz otherwise we cant balance the Parenthesis
        if (close > open){
            string op2 = op;
            op2.push_back(')');
            solve(open, close-1, op2, ans);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string  op = "";
        int open = n;
        int close = n;
        vector<string> ans;
        solve(open, close, op, ans);
        return ans;
    }
};