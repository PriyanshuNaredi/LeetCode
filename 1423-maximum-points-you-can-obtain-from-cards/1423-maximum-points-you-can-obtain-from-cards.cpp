class Solution {
public:
    int slidingWindow(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i = 0, j = 0;
        int len = n - k;
        long long total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        long long mn = INT_MAX;

        if (len == 0) {
            return total;
        }

        long long sum = 0;
        while (j < n) {
            sum += cardPoints[j];
            if (j - i + 1 < len) {
                j++;
            } else if (j - i + 1 == len) {
                mn = min(mn, sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        return total - mn;
    }

    int pointerApproch(vector<int>& cardPoints, int k){
        int lsum = 0, rsum=0;
        for(int i=0; i<k; i++)
            lsum += cardPoints[i];
        int maxSum = lsum;
        int right = cardPoints.size() - 1;
        for(int i = k - 1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[right];
            right--;
            maxSum = max(maxSum, (lsum+rsum));
        }
        return maxSum;
    }

    int maxScore(vector<int>& cardPoints, int k){
        return pointerApproch(cardPoints, k);
    }
};