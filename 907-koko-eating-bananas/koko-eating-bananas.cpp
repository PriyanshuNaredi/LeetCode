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
    int minEatingSpeed(vector<int>& piles, int h) {
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
};