//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        // return betterSol(arr);
        // return betterSolHashMap(arr);
        // return opt1(arr);
        return opt2(arr);
    }
    
    vector<int> opt1(vector<int>& a){
        // s - S_
        // s2 - S2_
        int n = a.size();
        long long S_ = (n * (n+1)) / 2;
        long long S2_ = (n * (n+1) * (2*n+1)) / 6;
        long long s = 0, s2 = 0;
        for(int i =0; i<n; i++){
            s += a[i];
            s2 += (long long) a[i] * (long long) a[i];
        }
        
        long long val1 = s - S_; // X - Y
        long long val2 = s2 - S2_; // X^2 - Y^2
        val2 = val2 / val1; // X + Y
        long long x = (val1 + val2) / 2;
        long long y = x - val1; 
        
        return { (int) x, (int) y};
        
    }
    
    vector<int> opt2(vector<int>& a){
        long long n = a.size();
        int xr = 0;
        for(int i=0; i<n; i++){
            xr = xr ^ a[i];
            xr = xr ^ (i+1);
        }
        // finding diffrenciating bit
        int bitNo = 0;
        while(1){
            if ( (xr & (1 << bitNo)) != 0){
                break;
            }
            bitNo++;
        }
        
        int zero = 0, one = 0;
        for(int i=0; i<n; i++){ // array part club finder
            if( (a[i] & (1 << bitNo)) != 0){
                // part of one bit club
                one = one ^ a[i];
                
            }else{
                // part of zero bit club
                zero = zero ^ a[i];
            }
        }
        for(int i=1; i<=n; i++){ // 1..n series bit club finder
            if( (i & (1 << bitNo)) != 0){
                // part of one bit club
                one = one ^ i;
                
            }else{
                // part of zero bit club
                zero = zero ^ i;
            }
        }
        
        int cnt =0;
        for(int i=0; i<n; i++){
            if(a[i] == zero){
                cnt++;
                
            }
        }
        
        return (cnt == 2) ? std::vector<int>{zero, one} : std::vector<int>{one, zero};
    }
    
    vector<int> betterSol(vector<int>& a){
        int n = a.size();
        int hash[n+1] = {0};
        
        for(int i=0; i<n; i++){
            hash[a[i]]++;
        }
        
        int repeating = -1, missing =-1;
        
        for(int i=1; i<=n; i++){
            if(hash[i] == 2) repeating = i;
            else if(hash[i] == 0) missing = i;
            
            if( repeating != -1 && missing != -1) break; 
        }
        return {repeating, missing};
    }
    
    vector<int> betterSolHashMap(vector<int>& a) {
        unordered_map<int, int> hash;
        int n = a.size();
        
        // Count the occurrences of each number
        for (int i = 0; i < n; i++) {
            hash[a[i]]++;
        }
        
        int repeating = -1, missing = -1;
        
        // Iterate through numbers from 1 to n to find the repeating and missing numbers
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) repeating = i;  // Found a repeating number
            else if (hash[i] == 0) missing = i; // Found a missing number
            
            if (repeating != -1 && missing != -1) break; 
        }
        
        return {repeating, missing};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends