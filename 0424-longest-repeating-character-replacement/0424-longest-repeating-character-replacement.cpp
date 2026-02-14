class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        while (j < n) {
            // J calc
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);

            // WD size
            if (j - i + 1 - maxi <= k) {
                // ans store
                ans = max(ans, j - i + 1);
                j++;
            } else if (j - i + 1 - maxi > k) {
                // i calc
                while (j - i + 1 - maxi != k) {
                    mp[s[i]]--;
                    maxi = max(maxi, mp[s[i]]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};