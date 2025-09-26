class Solution {
private:
    void solve(string input, string op, vector<string>& output) {

        if (input.length() == 0) {
            output.push_back(op);
            return;
        }

        if (isalpha(input[0])) {
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(input[0]));
            op2.push_back(toupper(input[0]));
            input.erase(input.begin() + 0);
            solve(input, op1, output);
            solve(input, op2, output);
        }
        else {
            string op1 = op;
            op1.push_back(input[0]);
            input.erase(input.begin() + 0);
            solve(input, op1, output);
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        // INPUT OUTPUT METHOD ADITYA VERMA
        string input = s;
        string op = "";
        vector<string> output;
        solve(input, op, output);
        return output;
    }
};