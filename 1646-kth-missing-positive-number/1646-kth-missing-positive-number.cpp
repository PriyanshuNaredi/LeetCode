class Solution {
public:
// Brute
int bf(vector < int > vec, int n, int k) { //O(n)
    for (int i = 0; i < n; i++) {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}
// Optimal {B.S.}
int os(vector < int > vec, int n, int k) {//O(logn)
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        return os(arr,n,k);
    }
};