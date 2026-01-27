class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (auto ch : num) {
            while (st.size() > 0 and k > 0 and (st.top() - '0') > (ch - '0')) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while (k > 0) {
            if (st.empty())
                return "0";
            else {
                st.pop();
                k--;
            }
        }
        if (st.empty())
            return "0";

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        while (res.size() > 0 and res.back() == '0') {
            res.pop_back();
        }
        if (res.empty())
            return "0";
            
        reverse(res.begin(), res.end());
        return res;
    }
};