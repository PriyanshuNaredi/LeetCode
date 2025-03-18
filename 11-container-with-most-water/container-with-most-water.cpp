class Solution {
public:
    int maxArea(vector<int>& arr) {

        int i = 0, j = arr.size() - 1, ans = 0;

        while( i < j ){
            int curr = (min(arr[i], arr[j]))*(j-i);
            ans = max(curr, ans);
            if (arr[i] < arr[j]) i++;
            else j--;

        }
        return ans;
    }
};