class Solution {
    int getNum(const string& s, int i, long result, int sign) {
        if (i >= s.size() || !isdigit(s[i]))
            return sign * result;

        result = result * 10 + (s[i] - '0');
        if (sign * result >= INT_MAX) return INT_MAX;
        if (sign * result <= INT_MIN) return INT_MIN;

        return getNum(s, i + 1, result, sign);
    }

public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;
        while (i < s.size() && s[i] == ' ') i++;

        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && s[i] == '0') i++;

        return getNum(s, i, 0L, sign);
    }
};