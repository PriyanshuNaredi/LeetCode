class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                if (st.size() > 0) {
                    ans.push_back(c);
                }
                st.push(c);
            } else {
                st.pop();
                if (st.size() > 0) {
                    ans.push_back(c);
                }
            }
        }

        return ans;
    }
};