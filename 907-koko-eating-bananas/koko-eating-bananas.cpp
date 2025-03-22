class Solution {
public:
    double calTotalHrs(vector<int> piles, int hourly) {
        double totalhrs = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            totalhrs += ceil((double)piles[i] / (double)hourly);
        }
        return totalhrs;
    }
    int mySol(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        cout << high;
        while (low <= high) {
            int mid = (low + high) / 2;

            double totalhrs = calTotalHrs(piles, mid);

            if (totalhrs <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
    int betterExecutionTime(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()) + 1;
        int ans = 1;
        while (l < r) {
            int m = (r - l) / 2 + l;
            int count = 0;

            for (int i = 0; i < piles.size(); i++) {
                count += (piles[i] / m);
                count += (piles[i] % m == 0) ? 0 : 1;
            }
            // cout << m << " count : " <<count <<endl;
            if (count > h) {
                l = m + 1;

            } else {
                r = m;
                ans = m;
            }
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        return betterExecutionTime(piles, h);
    }
};