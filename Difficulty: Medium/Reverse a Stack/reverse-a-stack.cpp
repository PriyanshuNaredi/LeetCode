
class Solution {
    void insert(stack<int> &st, int ele){
        if(st.size()==0){
            st.push(ele);
            return;
        }
        int temp = st.top();
        st.pop();
        insert(st, ele);
        st.push(temp);
    }
  public:
    void reverse(stack<int> &St) {
        // code here
        if(St.size()<=1){
            return;
        }
        int temp = St.top();
        St.pop();
        reverse(St);
        insert(St, temp);
    }
};