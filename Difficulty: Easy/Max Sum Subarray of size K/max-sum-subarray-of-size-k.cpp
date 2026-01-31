class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        
        while(j<arr.size()){
            sum += arr[j];
            if((j-i+1) < k)
                j++;
            else if((j-i+1) == k){
                maxSum = max(maxSum, sum);
                sum -= arr[i];
                j++;
                i++;
            }
        }
        return maxSum;
    }
};