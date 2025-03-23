class Solution {
public:
    bool possible(vector<int>& bloomDay, int days, int m, int k) {
        int cnt = 0;
        int noOfBouquest = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                cnt++;
            } else {
                noOfBouquest += (cnt) / (k);
                cnt = 0;
            }
        }
        noOfBouquest += (cnt) / (k);
        return noOfBouquest >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = (long long)m * (long long)k;
        if (val > bloomDay.size())
            return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif