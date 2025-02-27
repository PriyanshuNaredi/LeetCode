class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &arr)
        {

           	// Optimal Solution
            int n = arr.size();
            vector<vector < int>> ans;
            sort(arr.begin(), arr.end());
            for (int i = 0; i < arr.size(); i++)
            {
               	//remove duplicates:
                if (i != 0 && arr[i] == arr[i - 1]) continue;

               	//moving 2 pointers:
                int j = i + 1;
                int k = n - 1;
                while (j < k)
                {
                    int sum = arr[i] + arr[j] + arr[k];
                    if (sum < 0)
                    {
                        j++;
                    }
                    else if (sum > 0)
                    {
                        k--;
                    }
                    else
                    {
                        vector<int> temp = { arr[i],
                            arr[j],
                            arr[k]
                        };
                        ans.push_back(temp);
                        j++;
                        k--;
                       	//skip the duplicates:
                        while (j < k && arr[j] == arr[j - 1]) j++;
                        while (j < k && arr[k] == arr[k + 1]) k--;
                    }
                }
            }
            return ans;

            /*
           	// Better Solution
            set<vector < int>> st;
            int n = arr.size();

            for (int i = 0; i < n; i++)
            {
                set<int> hashmap;
                for (int j = i + 1; j < n; j++)
                {
                    int k = -(arr[i] + arr[j]);
                    if (hashmap.find(k) != hashmap.end())
                    {
                        vector<int> temp = { arr[i],
                            arr[j],
                            k
                        };
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashmap.insert(arr[j]);
                }
            }

            vector<vector < int>> ans(st.begin(), st.end());
            return ans;
            */
        }
};