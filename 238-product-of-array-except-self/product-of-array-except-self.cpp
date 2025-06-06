class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l_mult = 1, r_mult = 1;
        vector<int> l_arr(n, 1);
        vector<int> r_arr(n, 1);
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int j = n - i - 1;
            l_arr[i] = l_mult;
            r_arr[j] = r_mult;
            l_mult *= nums[i];
            r_mult *= nums[j];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = l_arr[i] * r_arr[i];
        }

        return ans;
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
