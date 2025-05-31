class Solution {
public:
    string largestOddNumber(string num) {
        // directly check id the last digit is odd then the whole no is odd.
        int i = num.length() - 1;
        if (((int)num[i]) % 2 != 0) {
            cout << "Direct ";
            return num;
        }

        for (int i = num.length(); i >= 0; i--) {
            if (((int)num[i]) % 2 != 0) {
                // here return i+1 as the last index is excluded while using the
                // substr function
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
