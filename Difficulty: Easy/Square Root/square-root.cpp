//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int low = 0, high = n;
        
        int ans = INT_MIN;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int mid_sq = mid * mid;
            if (mid_sq == n) return mid;
            else if (mid_sq < n) {
                ans = max(ans, mid);
                low = mid + 1;
                
            }
            else high = mid - 1;
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends