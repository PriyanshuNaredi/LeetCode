class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlength = INT_MAX;
        for (auto i : strs){
            minlength = min(minlength, (int)i.length());
        }

        int i = 0;
        while (i < minlength) {
            for (auto s : strs){
                cout << i << " " << s[i] << " " << strs[0][i] << endl;
                if (s[i] != strs[0][i]){
                    return s.substr(0,i);
                }
            }
            i += 1;
        }

        return strs[0].substr(0,i);
    }
};