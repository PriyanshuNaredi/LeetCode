class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxHeap;
        
        for(int i=0; i < arr.size(); i++){
            maxHeap.push(arr[i]);
            if(maxHeap.size() > k)
                maxHeap.pop();
        }
        return maxHeap.top();
    }
};