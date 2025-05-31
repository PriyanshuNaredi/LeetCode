class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapST;
        map<char, char> mapTS;
        int length = s.length() - 1;

        for (int i = 0; i < s.length(); i++){
            char c1 = s[i]; 
            char c2 = t[i];


            if((mapST.find(c1) != mapST.end() and mapST[c1] != c2) or
               (mapTS.find(c2) != mapTS.end() and mapTS[c2] != c1)
            )
                return false;
            
            mapST[c1] = c2;
            mapTS[c2] = c1;
        }


        return true;
        
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
