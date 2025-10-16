class Solution {
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void backtrack(int index, string& s, vector<string> path,
                   vector<vector<string>> &res) {

        // If index reaches end of string, store current partition
        if (index == s.length()) {
            res.push_back(path);
            return;
        }

        // Try all possible substrings
        for (int i = index; i < s.length(); i++) {
            // If substring is a palindrome
            if (isPalindrome(s, index, i)) {
                // Add substring to current path
                path.push_back(s.substr(index, i - index + 1));
                // Recur for remaining string
                backtrack(i + 1, s, path, res);
                // Backtrack to try other partitions
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, s, path, res);
        return res;
    }
};