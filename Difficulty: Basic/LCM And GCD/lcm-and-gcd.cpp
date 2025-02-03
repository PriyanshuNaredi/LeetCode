//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


/*
Find GCD using Euclidean Formula 

update the values of a and b using modulo of the g rater of two or b.

after finding GCD, LCM can be calculated using (orgA * orgB ) / (a or b who is not zero)
*/

// } Driver Code Ends
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        vector<int> ans;
        int orgA = a;
        int orgB = b;
        
        while (a > 0 && b > 0 ){
            if (a>b){
                a = a % b;
            } else {
                b = b % a;
            }
        }
        
        if (a == 0){
            int lcm = (orgA * orgB) / b;
            ans.push_back(lcm);
            ans.push_back(b);
        } else {
            int lcm = (orgA * orgB) / a;
            ans.push_back(lcm);
            ans.push_back(a);
            
        }
        
        
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
