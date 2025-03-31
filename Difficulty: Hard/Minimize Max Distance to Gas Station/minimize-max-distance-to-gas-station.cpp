//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double bruteForce(vector<int> &stations, int k) {
        // Code here
        int n  =  stations.size();
        vector<int> howMany(n-1,0);
        
        for (int gasS = 1; gasS <= k; gasS++){
            long double maxS = -1;
            int maxIndex = -1;
            for (int i=0; i<n-1; i++){
                long double diff = stations[i+1] - stations[i];
                long double secLength = diff / (long double) (howMany[i]+1);
                if(secLength > maxS){
                    maxS = secLength;
                    maxIndex = i;
                }
            }
            howMany[maxIndex]++;
        }
        long double maxAns = -1;
        for (int i=0; i<n-1; i++){
            long double diff = stations[i+1] - stations[i];
            long double secLength = diff / (long double) (howMany[i]+1);
            maxAns = max(maxAns, secLength);
        }
        return maxAns;
    }
    
    double betterSol(vector<int> &stations, int k) {
        // Code here
        int n  =  stations.size();
        vector<int> howMany(n-1,0);
        priority_queue<pair<long double,int>> pq;
        
        // store initial section lenghts in pq
        for (int i=0; i<n-1; i++){
            pq.push( {stations[i+1] - stations[i], i} );
        }
        
        for (int gasS = 1; gasS <= k; gasS++){
            auto tp = pq.top();
            pq.pop();
            int secIndex = tp.second;
            howMany[secIndex]++;
            long double initDiff = stations[secIndex + 1] - stations[secIndex];
            long double newSecLen = initDiff / (long double) (howMany[secIndex] + 1);
            pq.push( {newSecLen, secIndex});
        }

        return pq.top().first;
    }
    
    int noOfGasStationReq( vector<int> &stations, long double dist){
        int cnt = 0;
        for (int i=1; i<stations.size(); i++){
            int noInBetween = ((stations[i] - stations[i-1]) / dist);
            if ((stations[i] - stations[i-1]) / dist == noInBetween * dist){
                noInBetween--;
            }else{
                cnt += noInBetween;
            }
        }
        return cnt;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Optimal Sol
        int n  =  stations.size();
        long double low = 0, high = 0;
        
        for (int i=0; i < n-1; i++){
            high = max(high, (long double)(stations[i+1] - stations[i]));
        }
        
        long double diff = 1e-6;
        
        while (high - low > diff){
            long double mid = ( low + high ) / (2.0);
            int cnt = noOfGasStationReq(stations, mid);
            if (cnt > k) 
                low = mid;
            else
                high = mid;
        }
        
        return high;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends