class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        int n = ( n1 + n2 );
        int ind1 = n / 2;
        int ind2 = ind1 - 1;
        int cnt = 0;
        int ind1elem = -1, ind2elem = -1;

        while (i < n1 and j < n2){
            if (nums1[i] < nums2[j]){
                if (cnt == ind1) ind1elem = nums1[i];
                if (cnt == ind2) ind2elem = nums1[i];
                cnt ++;
                i++;
            }else{
                if (cnt == ind1) ind1elem = nums2[j];
                if (cnt == ind2) ind2elem = nums2[j];
                cnt ++;
                j++;
            }
        }

        while (i < n1){
            if (cnt == ind1) ind1elem = nums1[i];
            if (cnt == ind2) ind2elem = nums1[i];
            cnt ++;
            i++;
        }

        while ( j < n2 ){
            if (cnt == ind1) ind1elem = nums2[j];
            if (cnt == ind2) ind2elem = nums2[j];
            cnt ++;
            j++;
        }

        if ( n % 2 == 1) return ind1elem;
        else return (double)((double)( ind1elem + ind2elem) / 2);

    }
};