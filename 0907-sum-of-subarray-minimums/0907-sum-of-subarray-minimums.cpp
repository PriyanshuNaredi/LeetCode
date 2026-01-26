class Solution {
    vector<int> findNSL(vector<int> arr) {
        // Will store index of NSL rather than Value
        /*
        stack<int> st;
        vector<int> v(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() and arr[st.top()] > arr[i])
                st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
        */
            stack<pair<int,int>> st;
            vector<int> v(arr.size());

            for (int i = 0; i < arr.size(); i++) {
                while (!st.empty() && st.top().first > arr[i])
                    st.pop();

                v[i] = st.empty() ? -1 : st.top().second;
                st.push({arr[i], i});
            }
            return v;
        
    }

    vector<int> findNSR(vector<int> arr) {
        // Will store index of NSL rather than Value
        
        stack<int> st;
        vector<int> v(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            v[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return v;
        /*
        stack<pair<int, int>> st; // {arr[i],i}
        vector<int> v;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (st.size() == 0)
                v.push_back(arr.size());
            else if (st.size() > 0 and st.top().first < arr[i])
                v.push_back(st.top().second);
            else if (st.size() > 0 and st.top().first >= arr[i]) {
                while (st.size() > 0 and st.top().first >= arr[i])
                    st.pop();
                if (st.size() == 0)
                    v.push_back(arr.size());
                else
                    v.push_back(st.top().second);
            }
            st.push({arr[i], i});
        }
        reverse(v.begin(), v.end());
        return v;
        */
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nsl = findNSL(arr);
        vector<int> nsr = findNSR(arr);
        int total = 0;
        int MOD = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            int left = i - nsl[i];
            int right = nsr[i] - i;
            /* Count of subarrays where 
            current element is minimum */
            long long freq = left*right*1LL;
            
            // Contribution due to current element 
            int val = (freq*arr[i]*1LL) % MOD;
            
            // Updating the sum
            total = (total + val) % MOD;
        }
        return total;
    }
};