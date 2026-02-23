class Solution {
public:
    vector<int> frequencySort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mpp;
        for(auto it: arr){
            mpp[it]++;
        }
        
        for(auto it: mpp){
            pq.push({-it.second, it.first}); 
        }

        while(pq.size() > 0){
            int freq = pq.top().first;
            int ele = pq.top().second;
            for(int i = 0; i<abs(freq);i++){
                res.push_back(ele);
            }
            pq.pop();
        }
        return res;
    }
};