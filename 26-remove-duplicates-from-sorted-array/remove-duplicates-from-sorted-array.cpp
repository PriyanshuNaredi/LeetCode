class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0;
        for (int j=0; j< arr.size(); j++){
            if (arr[i] != arr[j]){
                arr[i+1] = arr[j];
                i++;
            }
        }
        return i+1;
    }
};