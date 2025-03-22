class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) { // increase the msb by 1 if the last digit is not 9
                digits[i] += 1;
                return digits;
            }
            // make the last digit 0 until we get to the last index 
            // then increase the size of vector by one 
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;        
    }
};