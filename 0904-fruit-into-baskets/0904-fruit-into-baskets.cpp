class Solution {
public:
    int totalFruit(vector<int>& s) {
        // same as Longest sunstring with k unique chars
        // codition(k) : 2
        int k = 2;
        int i=0, j=0;
        int ans = 1;
        unordered_map<int,int> mp;

        while(j < s.size()){
            mp[s[j]]++; // j calc
            // if(mp.size() < k)
            //     j++;
            if(mp.size() <= k){
                ans = max(ans, (j-i+1));
                j++;
            }
            else if(mp.size() > k){
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};