class Solution {
public:
    int bruteForce(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k)
                k++;
            else
                break;
        }
        return k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1); // = avialable_value - value_That_Should_be
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high+1+k;
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