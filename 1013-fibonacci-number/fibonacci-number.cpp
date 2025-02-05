class Solution {
public:
    int fib(int n) {
        vector<int> arr(n+1,-1);
        return fibIterative(n);
    }
    int fibRecursion(int n) {
        if ( n == 1) return 1;
        if ( n == 0 ) return 0;
        return fib(n-1) + fib(n-2);
    }

    int fibRecMem(int n, std::vector<int> &arr) {
        // Base cases
        if (n == 0) return 0; // fib(0) = 0
        if (n == 1) return 1; // fib(1) = 1

        // Check if already computed
        if (arr[n] != -1) {
            return arr[n];
        }

        // Recursive calculation with memoization
        arr[n] = fibRecMem(n - 1, arr) + fibRecMem(n - 2, arr);
        return arr[n];
    }
// Bottom-up DP
    int fibIterative(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> fib(n + 1);
        fib[0] = 0;
        fib[1] = 1;

        for (int i = 2; i <= n; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2]; 
        }

        return fib[n];
    }
};