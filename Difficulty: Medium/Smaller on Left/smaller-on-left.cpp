vector<int> Smallestonleft(int arr[], int n) {
    // code here
    vector<int> ans;
    set<int> s;
    for (int i = 0; i < n; i++) {
        // Find the first element >= arr[i]
        auto it = s.lower_bound(arr[i]);
        
        if (it == s.begin()) {
            // Set ka sabse chhota element >= arr[i] hai
            // Matlab koi strictly smaller element nahi hai
            ans.push_back(-1);
        } else {
            // Step back to get the greatest strictly smaller value
            --it;
            ans.push_back(*it);
        }
        
        // Insert current element for next iterations
        s.insert(arr[i]);
    }
    return ans;

}  //tc = O(n*logn)

//  why?

// lower_bound() on set: O(log n)
// insert() on set: O(log n)
// Total for n elements: O(n log n) 