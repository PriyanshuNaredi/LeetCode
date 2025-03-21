//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int func(int mid, int n){
      long long ans = 1;
      while(n > 0){
          if(n % 2 == 1){
              ans = ans * mid;
              n = n - 1;
          }else{
              mid = mid * mid;
              n = n / 2;
          }
      }
      return ans;
  }
    int nthRoot(int n, int m) {
        // Code here.
        int low = 1, high = m;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int midN = func(mid,n);
            if(midN == m) return mid;
            else if (midN < m) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends