class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        for(int i = 0; i<arr.size(); i++){
            minHeap.push(arr[i]);
        }
        
        int cost = 0;
        
        while(minHeap.size() >= 2){
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            cost += first + second;
            minHeap.push(first + second);
        }
        return cost;
    }
};