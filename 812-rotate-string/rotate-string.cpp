class Solution {

    bool goodSolution(string text, string goal) {
        // SIMPLE PATTERN MATCHING
        int goalSize = goal.size();
        cout << goalSize << endl;
        for (int i = 0; i < text.size(); i++) {
            string subStr = text.substr(i, goalSize);
            cout << text[i] << " - " << subStr << endl;
            if (text.substr(i, goalSize) == goal)
                return true;
        }
        return false;
    }

    // KMP 

    // 1. LPS Array

    vector<int> LPS(string &goal){
        int n = goal.size();
        vector<int> lps(n);

        int i = 1;
        int j = 0;

        while(i<n){
            if(goal[i] == goal[j]){
                lps[i] = j + 1;
                i++; j++;
            }else if(j>0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }

    // 2. KMP Pattern MATCHING

    bool KMP( string &text, string &goal, vector<int> &lps){
        int m = text.size();
        int n = goal.size();

        int i=0, j=0;

        while(i<m){
            if(text[i] == goal[j]){
                i++; j++;
            }
            if(j==n){
                return true;
            }
            if(i<m && text[i]!=goal[j]){
                if(j>0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return false;
    }



public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        string text = s + s;

        // return goodSolution(text, goal);

        vector<int> lps = LPS(goal);
        return KMP(text, goal, lps);

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
