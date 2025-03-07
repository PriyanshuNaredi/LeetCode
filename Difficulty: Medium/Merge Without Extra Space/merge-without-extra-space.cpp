//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    void isGreater( vector<int>& nums1, vector<int>& nums2, int i, int j){
        if ( nums1[i] > nums2[j]){
            swap(nums1[i] , nums2[j]);
        }
    }
  public:
    void mergeArrays(vector<int>& nums1, vector<int>& nums2) {
        // code here
        // bf(nums1, nums2);
        // opt1(nums1, nums2);
        opt2(nums1, nums2);
    }

    void opt2( vector<int>& nums1, vector<int>& nums2){
        
        int n = nums1.size(), m = nums2.size();
        
        int len = n + m;
        int gap = (len / 2) + (len % 2);
        while( gap > 0){
            int left = 0, right = left + gap;
            while(right < len){
                // left in in nums1 and right is in nums2
                if ( left < n && right >= n){
                    
                    isGreater(nums1, nums2, left, right - n);
                    
                }else if(left >= n){ // left and right both in nums2
                
                    isGreater(nums2, nums2, left - n, right - n);
                    
                }else{ // both in nums1
                
                    isGreater(nums1, nums1, left, right);
                    
                }
                left ++, right ++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
    
    void opt1(vector<int>& nums1, vector<int>& nums2){
        
        int n = nums1.size(), m = nums2.size();
        int left = n-1, right =0;
        
        while (left >= 0 && right < n){
            if (nums1[left] > nums2[right]){
                swap(nums1[left] , nums2[right]);
                left --, right++;
            }
            else break;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
    }
    
    void bf (vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size(), m = nums2.size();
        vector<long long> nums3(m + n);
        int left = 0, right = 0, index = 0;

        while (left < n && right < m) {
            if (nums1[left] <= nums2[right]) {
                nums3[index] = nums1[left];
                left++, index++;
            } else {
                nums3[index] = nums2[right];
                right++, index++;
            }
        }

        while (left < n) {
            nums3[index++] = nums1[left++];
        }

        while (right < n) {
            nums3[index++] = nums1[right++];
        }

        for (int i = 0; i < m + n; i++) {
            if (i < n)
                nums1[i] = nums3[i];
            else
                nums2[i - n] = nums3[i];
        }
    }
};


//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends