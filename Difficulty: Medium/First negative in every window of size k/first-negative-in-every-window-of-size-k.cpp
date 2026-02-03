class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> v;
        deque<int> dq; // stores indices of negative elements

        for (int i = 0; i < arr.size(); i++) {
            // Remove indices that are out of the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Add current index if it's negative
            if (arr[i] < 0)
                dq.push_back(i);

            // Once we've formed the first window of size k, record the answer
            if (i >= k - 1) {
                if (dq.empty())
                    v.push_back(0);
                else
                    v.push_back(arr[dq.front()]); // front = leftmost negative in window
            }
        }
        return v;
    }
};