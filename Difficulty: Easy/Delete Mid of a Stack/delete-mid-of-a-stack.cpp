class Solution {
    void solve(stack<int> &s, int k){
        if(k==1){
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        solve(s, k-1);
        s.push(temp);
    }
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int size = s.size();
        if(size == 0)
            return;
        int k = size/2 + 1;
        solve(s, k);
    }
};