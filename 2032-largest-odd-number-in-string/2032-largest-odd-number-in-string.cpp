class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.length(); i >= 0; i--)
        {
            // char to ascii conversion by subtraction 48 (ASCII of 0)
            if((int)(num[i] - 48) % 2 != 0)
            {
                // here return i+1 as the last index is excluded while using the substr function
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};