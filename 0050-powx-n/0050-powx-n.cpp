class Solution {
    double iterSol(double x, int n) {
        double ans = 1.0;
        long long nn = n;

        if (nn < 0)
            nn = -1 * nn;

        while (nn) {
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);

        return ans;
    }

    double recSol(double x, int n){
        if(n == 0)
            return 1.0;
        double half = recSol(x, n/2);
        // x^n 
        if(n % 2 == 0)
            return half * half;
            // if n even => x^n = (x^(n/2))^2
        else
            return half * half * x;
            //  if n odd => x^n = ((x^(n/2))^2) * x 
    }

public:
    double myPow(double x, int n) {
        // return iterSol(x, n);
        long long nn = n;
        if(nn<0){
            x = 1/x;
            nn = -nn;
        }
        return recSol(x, nn);
    }
};