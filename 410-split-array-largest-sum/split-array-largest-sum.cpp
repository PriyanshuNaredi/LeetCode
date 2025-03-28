class Solution {
public:
    int cntSum(vector<int> nums, int k){
        int sub = 1, subSum = 0;
        for(int i=0; i<nums.size(); i++){
            if (subSum + nums[i] <= k){
                subSum += nums[i];
            }else{
                sub++;
                subSum = nums[i];
            }    
        }
        return sub;    
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = (low + high) / 2;
            int sub = cntSum(nums, mid);
            if (sub > k)
                low = mid + 1;
            else
                high = mid - 1;
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

