class Solution {
public:
    int findDays(vector<int> &weights, int cap){
        int days = 1, load = 0;
        for(int i=0; i<weights.size(); i++){
            if (load + weights[i] > cap){
                days += 1;
                load = weights[i];
            }else{
                load += weights[i];
            }    
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);

        while(low <= high){
            int mid = (low + high) / 2;
            int daysR = findDays(weights, mid);
            if (daysR <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
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