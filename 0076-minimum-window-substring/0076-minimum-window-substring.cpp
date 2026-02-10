class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto ch : t)
            mp[ch]++;

        int i = 0, j = 0;
        int count = mp.size();
        int start = 0, end = INT_MAX;

        while (j < s.size()) {
            // j calc
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;

            // window size
            // dec window size to find the smallest ans
            if (count == 0) {
                // find the mini window size
                while (count == 0) {
                    if (end > (j - i + 1)) {
                        end = j - i + 1;
                        start = i;
                    }
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        if (mp[s[i]] == 1)
                            count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if (end != INT_MAX)
            return s.substr(start, end);
        return "";
    }
};