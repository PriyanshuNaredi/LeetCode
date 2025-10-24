class Solution {
    void solve(int index, string path, long currentTotal, long lastOperand,
               string& num, int target, vector<string>& result) {
        
        // --- Base Case ---
        // If we have reached the end of the 'num' string...
        if (index == num.length()) {
            // ...we check if the expression's value is the target.
            if (currentTotal == target) {
                // If yes, we found a valid answer.
                result.push_back(path);
            }
            // Whether it matches or not, we must stop recursing on this path.
            return;
        }

        // --- Recursive Step ---
        // We loop to build our *next* number. This loop can create numbers
        // of different lengths (e.g., "1", "12", "123").
        string currentNumStr = "";
        long currentNum = 0;

        for (int i = index; i < num.length(); i++) {
            // Add the next digit to our current number string
            currentNumStr += num[i];
            
            // Convert the string to a long to prevent overflow
            currentNum = stol(currentNumStr);

            // --- The Choices ---
            
            // 1. The "First Number" Case
            // If index is 0, we can't add an operator. We just
            // pick the number and start the recursion.
            if (index == 0) {
                solve(i + 1,        // Next index to start from
                      path + currentNumStr, // Path is just the number itself
                      currentNum,     // Total is just this number's value
                      currentNum,     // Last operand is also this number
                      num, target, result);
            } 
            
            // 2. The "Subsequent Numbers" Case
            // We have our 3 operator choices: +, -, *
            else {
                // Choice: +
                solve(i + 1, path + "+" + currentNumStr,
                      currentTotal + currentNum, currentNum,
                      num, target, result);

                // Choice: -
                solve(i + 1, path + "-" + currentNumStr,
                      currentTotal - currentNum, -currentNum, // Note: lastOperand is -currentNum
                      num, target, result);

                // Choice: * (The special one!)
                // (currentTotal - lastOperand) + (lastOperand * currentNum)
                solve(i + 1, path + "*" + currentNumStr,
                      (currentTotal - lastOperand) + (lastOperand * currentNum),
                      lastOperand * currentNum, // The new lastOperand
                      num, target, result);
            }

            // --- Leading Zero Trap ---
            // If the number we just processed was "0", we must stop.
            // We can't form "01", "05", etc.
            if (num[index] == '0') {
                break;
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result; // This will store our answers
        
        // Start the recursive process.
        // We begin at index 0, with an empty path, 0 total, and 0 last operand.
        solve(0, "", 0, 0, num, target, result);
        
        return result;
    }
};

/* 
Explanation of the Code
1. addOperators (The Main Function)
vector<string> result;: This is just an empty list to store all the valid expression strings we find.

solve(0, "", 0, 0, num, target, result);: This is the "ignition" \U0001f680. It kicks off our recursive helper function.

0: We start at index 0 of the num string.

"": Our initial path (the expression string) is empty.

0: The currentTotal value is 0.

0: The lastOperand is 0. This value doesn't matter for the first number, which is handled by the if (index == 0) case.

2. solve (The Recursive Helper)
Parameters
int index: Where in the num string are we starting from? (e.g., at num[2]).

string path: The expression we've built so far (e.g., "1+2*3").

long currentTotal: The evaluated result of the path so far (e.g., 7). We use long to avoid integer overflow, as numbers can get big.

long lastOperand: The last number we just processed (e.g., 2 for the path "1+2"). This is the key for multiplication.

string& num, int target, vector<string>& result: These are just references to the original inputs and the result list.

Base Case
if (index == num.length()) { ... }

This means we have used up every single digit in the num string.

We check if our currentTotal equals the target. If it does, we add the path to our result list.

Recursive Step (The for loop)
This loop is responsible for building the next number to operate on.

If index is 2 (at the '3' in "12345"), this loop will try:

currentNum = "3" (i = 2)

currentNum = "34" (i = 3)

currentNum = "345" (i = 4)

For each of these numbers, it will try all 3 operator choices.

The Choices (Inside the for loop)
if (index == 0): This special case handles the very first number. Since it can't have a +, -, or * in front of it, we just add it to the path and set the currentTotal and lastOperand to its value.

else (The 3 Operators):

+: Simple. Add the new number to the currentTotal. The new lastOperand is just currentNum.

-: Simple. Subtract the new number. The new lastOperand is -currentNum. This is critical so that if we multiply next, we "undo" by subtracting a negative number (which is adding).

*: The magic formula.

New Total: (currentTotal - lastOperand) + (lastOperand * currentNum)

New lastOperand: lastOperand * currentNum

This correctly "re-evaluates" the last operation as a multiplication.

The Leading Zero Trap
if (num[index] == '0') { break; }

This check is placed after our 3 choices.

It means: "If the first digit of the number we just built was '0' (e.g., "0", "05", "012"), then we must stop this for loop."

This allows the single-digit "0" to be processed (when i == index), but prevents it from forming multi-digit numbers like "05", which are invalid.
*/