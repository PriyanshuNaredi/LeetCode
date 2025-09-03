class Solution {
    // O(log(exp))
public:
    const int MOD = 1e9 + 7;
    // Recursive function to compute (base^exp) % MOD efficiently
    long long modPow(long long base, long long exp) {
        // Base case: any number to the power 0 is 1
        if (exp == 0)
            return 1;

        // Recursively calculate half power
        long long half = modPow(base, exp / 2);
        // Square the result for the even part
        long long result = (half * half) % MOD;

        // If the exponent is odd, multiply by base once more
        if (exp % 2)
            result = (result * base) % MOD;

        return result;
    }

    // Main function to count good numbers for a string of length n
    int countGoodNumbers(long long n) {
        // Calculate number of even-indexed positions (0-based)
        long long even_positions = (n + 1) / 2;

        // Calculate number of odd-indexed positions
        long long odd_positions = n / 2;

        // For even positions, we have 5 choices (0, 2, 4, 6, 8)
        // For odd positions, we have 4 choices (2, 3, 5, 7)
        // Use modular exponentiation to avoid overflow for large n

        long long even_ways = modPow(5, even_positions);
        long long odd_ways = modPow(4, odd_positions);

        // Multiply ways for even and odd positions and take modulo
        long long answer = (even_ways * odd_ways) % MOD;

        return (int)answer;
    }
};