class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
    // will use stack to keep track of greater elements
    // traverse the array from back 
    // code&complexity reel - Day 44 and
    // https://www.geeksforgeeks.org/next-greater-element/#using-stack-on-time-and-on-space
    // https://leetcode.com/problems/next-greater-element-ii/solutions/127612/next-greater-element-ii
        int n = arr.size();
        vector<int> res(n,-1); // used to store the corresponding grater element
        stack<int> st;
        
        for ( int j=0; j<2; j++){
        for ( int i = n - 1; i >= 0; i--){
        // Pop elements from the stack that are less than
        // or equal to the current element
            while( !st.empty() && st.top() <= arr[i] ){
                st.pop();
            }
        // If the stack is not empty, the top element
        // is the next greater element
            if(!st.empty()) res[i] = st.top();
            
            st.push(arr[i]);
        }
        }
        return res;
    }
};