class Solution {
public:
    vector<int> bruteSol(vector<int>& arr, vector<vector<int>>& queries) {
        // Brute Force
        // TC -> (queries . n)
        vector<int> ans;
        for (auto q : queries) {
            int xorSum = 0;
            cout << q[0] << " - " << q[1] << endl;
            for (int i = q[0]; i <= q[1]; i++) {
                xorSum ^= arr[i];
            }
            ans.push_back(xorSum);
        }
        return ans;
    }

    vector<int> betterSol(vector<int>& arr, vector<vector<int>>& queries) {
        // TC -> O(n+q), SC -> O(n)

        int n = arr.size();
        vector<int> prefixXor(n + 1, 0);
        // store the XOR of entire arr
        // prefixXor = { (0), (arr[0]), (arr[0]^arr[1]), ...... }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " - ";
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
            cout << prefixXor[i + 1] << endl;
        }

        vector<int> result;
        for (auto q : queries) {
            result.push_back(prefixXor[q[1] + 1] ^ prefixXor[q[0]]);
        }
        return result;
    }

    vector<int> optimalSol(vector<int>& arr, vector<vector<int>>& queries) {
        // TC -> O(n+q), SC -> O(1)

        int n = arr.size();

        for (int i = 1; i < n; i++) {
            cout << i << " - " << "arr[i] " << arr[i];
            arr[i] ^= arr[i - 1];
            cout << " after XOR arr[i] " << arr[i] << endl;
        }

        vector<int> result;
        for (auto q : queries) {
            if (q[0] > 0)
                result.push_back(arr[q[0] - 1] ^ arr[q[1]]);
            else
                result.push_back(arr[q[1]]);
        }
        return result;
    }

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        return optimalSol(arr, queries);
    }
};