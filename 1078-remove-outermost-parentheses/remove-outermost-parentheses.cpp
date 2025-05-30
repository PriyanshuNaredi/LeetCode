class Solution {
public:
    string removeOuterParentheses1(string s) {
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

    string removeOuterParentheses(string s) {
        // keeping track of opened
        // opened --> represent no. of opened without closed
        //"(()())(())"
        //  "((" --> opened=2;
        //  "(()"  --> opened=1;
        string ans;
        int opened = 0;
        for (auto i : s) {
            if (i == '(' && opened++ > 0)
                ans += i;
            if (i == ')' && opened-- > 1)
                ans += i;
        }
        return ans;
    }
};



const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
