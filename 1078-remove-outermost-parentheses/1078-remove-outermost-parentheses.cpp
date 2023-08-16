class Solution {
public:
    string removeOuterParentheses(string s) {
        //keeping track of opened
        //opened --> represent no. of opened without closed 
        //"(()())(())"
        // "((" --> opened=2; 
        // "(()"  --> opened=1; 
        string ans;
        int opened=0;
        for(auto i:s){
            if(i=='(' && opened++>0)    ans+=i;
            if(i==')' && opened-->1)    ans+=i;    
        }
        return ans;
    }
};