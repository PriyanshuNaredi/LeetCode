class Solution {

    int findmax(vector<int> &piles){
        int maxi = 0 ;
        int n = piles.size();
        for(int i =0 ; i<n ;i++){
            maxi = max(piles[i],maxi);
        }
        return maxi;
    }

    double calculateTotalHrs(vector<int>& piles,int hourly){
        double totalH = 0;
        int n = piles.size();
        for(int i = 0 ; i <n ; i++){
            totalH += ceil((double)piles[i]/(double)hourly);
        }
        return totalH;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        while(low<=high){
            int mid = (low+high)/2;
            double totalH = calculateTotalHrs(piles,mid);
            if(totalH<=h){
                high=mid-1;
            }else{
                low = mid+1;
            }
        }return low;
    }
};