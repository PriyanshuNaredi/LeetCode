class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // Initialize operation count to 0
        int noOfOperations = 0;
        
        // Work backwards from target to startValue
        // We do this because finding the minimal path is easier in reverse:
        // - If target is even, the last operation could have been a multiply by 2
        // - If target is odd, the last operation must have been a subtract by 1
        while (target > startValue) {
            noOfOperations++; // Increment the operation count for each step

            if (target % 2 == 0) {
                // If target is even, the previous operation could be multiply by 2, so divide by 2
                target = target / 2;
            } else {
                // If target is odd, the only way to reach here going forward is target - 1
                // So, in reverse, add 1 to make it even for the next step
                target++;
            }
        }
        // After the loop ends, startValue >= target
        // The only possible move now is to subtract 1 repeatedly, so add the difference
        return noOfOperations + (startValue - target);
    }
};


/*
The goal is to find the minimum number of operations, using only multiplication
by 2 and subtraction by 1 (going forward from startValue to target). However,
solving this optimally is done by working backwards from target back to
startValue.

When working backwards:

If target is even: Divide it by 2, because multiplying by 2 forward is reversed
by dividing by 2.

If target is odd: target++ is used (add 1), because the only option, if arriving
at an odd number from valid moves, is that it must have previously been even and
then had 1 subtracted (moving forward). So, working backwards, 1 is added to
make it even, then it can be divided by 2.

If you do target-- in the odd case, mathematically, you move the target further
away from startValue and potentially perform extra moves, losing the optimal
property.

Working Example
Suppose startValue = 2 and target = 5:

target = 5 (odd) → target++ → 6 (even) → divide by 2 → 3 (odd), repeat

If you do target-- instead, then 5 → 4 (even) → 2, but this is not the correct
reversal of the operations allowed.
*/