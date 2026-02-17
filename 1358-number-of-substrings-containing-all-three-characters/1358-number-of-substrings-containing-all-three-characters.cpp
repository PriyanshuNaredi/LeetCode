class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = s.size();
        unordered_map<char, int> mp2;

        while (j < n) {
            if (s[j] == 'a' || s[j] == 'b' || s[j] == 'c') {
                mp2[s[j]]++;
            }

            while (mp2.size() == 3) {
                ans += n - j;
                if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c') {
                    mp2[s[i]]--;
                    if (mp2[s[i]] == 0) {
                        mp2.erase(s[i]);
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};