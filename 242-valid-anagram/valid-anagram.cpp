class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        // 1.
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
        */

        // 2.

        if (s.size() != t.size())   return false;

        unordered_map<char,int> mapS;
        unordered_map<char,int> mapT;

        for (int i=0; i<s.size(); i++){
            mapS[s[i]] += 1;
            mapT[t[i]] += 1;
        }

        // for (auto c:mapS){
        //     if(mapS[c] != mapT[c]){
        //         return false;
        //     }
        // }
        for (const auto& kv : mapS) {              // kv is pair<key, value>
            if (kv.second != mapT[kv.first]) {     // compare counts
                return false;
            }
        }
        return true;


        /*
        3.
        if (s.size() != t.size()) return false;

        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        for (char c : t) {
            if (--freq[c] < 0)     // extra char in t
                return false;
        }

        return true;
        */
    }
};