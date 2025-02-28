//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int xr = 0;
        map<int,int> mp;
        mp[xr]++; // {0,1}, init values for map
        int cnt = 0;
        
        for(int i=0; i<arr.size(); i++){
            // x = xr ^ k
            // find x in map =>
            //              If present then increase the counter
            // add the current xr, if not present
            // if alredy exist then increase the cnt for the no. of times xr appears
            xr = xr ^ arr[i];
            int x = xr ^ k;
            cnt += mp[x];    
            mp[xr]++;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends