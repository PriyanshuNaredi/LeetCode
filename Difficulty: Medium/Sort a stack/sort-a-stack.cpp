/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insertStack(stack<int> &s, int x){
    if(s.size()==0 || x>s.top()){
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insertStack(s,x);
    s.push(temp);
}
void SortedStack ::sort() {
    // Your code here
    if(s.size() == 0)
        return;
    int temp = s.top();
    s.pop();
    sort();
    insertStack(s, temp);
}