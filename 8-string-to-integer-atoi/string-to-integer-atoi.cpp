class Solution {
    int charToInti(const string& s, int i, int sign, long long result, bool numStarted, bool signHandled) {
        if (i >= s.size())
            return sign * result;

        // Skip leading spaces before any digit or sign
        if (!numStarted && !signHandled && s[i] == ' ')
            return charToInti(s, i + 1, sign, result, false, false);

        // Handle sign before digits only, and only once
        if (!numStarted && !signHandled && (s[i] == '-' || s[i] == '+')) 
            return charToInti(s, i + 1, (s[i] == '-') ? -1 : 1, result, false, true);

        // Parse digits
        if (isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign * result >= INT_MAX)
                return INT_MAX;
            if (sign * result <= INT_MIN)
                return INT_MIN;
            return charToInti(s, i + 1, sign, result, true, signHandled);
        }

        // If before parsing any digit, hit a non-space/non-sign/nondigit, return 0
        if (!numStarted)
            return 0;

        // Stop at first non-digit once number has started
        return sign * result;
    }

public:
    int myAtoi(string s) {
        return charToInti(s, 0, 1, 0, false, false);
    }
};
