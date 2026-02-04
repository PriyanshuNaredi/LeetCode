// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        unordered_map<char,int> mp;
        int ans = 0;
        
        for(auto ch : pat){
            mp[ch]++;
        }
        
        int count = mp.size();
        int k = pat.size();
        
        int i=0, j=0;
        
        while(j< txt.size()){
            // j cal
            if(mp.find(txt[j]) != mp.end()){
                mp[txt[j]] --;
                if(mp[txt[j]] == 0){
                    count --;
                }
            }
            
            // window size
            if(j-i+1 < k)
                j++;
            else if (j-i+1 == k){
                if(count == 0)
                    ans++;
                
                // i calc
                if(mp.find(txt[i]) != mp.end()){
                    mp[txt[i]]++;
                    if(mp[txt[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};




















