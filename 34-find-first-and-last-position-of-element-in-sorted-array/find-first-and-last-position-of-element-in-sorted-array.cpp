class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int lb = lowerBound(arr, arr.size(), target);
        int up = upperBound(arr, arr.size(), target);
        if (lb == arr.size() || arr[lb] != target)
            return {-1, -1};
        return {lb, up - 1};
    }

    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }

    int upperBound(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] > x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
};