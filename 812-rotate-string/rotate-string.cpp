class Solution {

public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        string text = s + s;
        int goalSize = goal.size();
        cout << goalSize << endl;
        for (int i = 0; i < text.size(); i++) {
            string subStr = text.substr(i, goalSize);
            cout << text[i] << " - " << subStr << endl;
            if (text.substr(i, goalSize) == goal)
                return true;
        }

        return false;
    }
};