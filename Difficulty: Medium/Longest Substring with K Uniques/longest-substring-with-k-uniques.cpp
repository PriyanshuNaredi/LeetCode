class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int> mp;
        int ans = -1;
        int i=0, j=0;
        
        while(j < s.size()){
            // j calc
            mp[s[j]]++;
            
            // codition
            if(mp.size() < k)
                j++;
            else if(mp.size() == k){
                ans = max(ans, (j-i+1));
                j++;
            }
            else if( mp.size() > k){
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