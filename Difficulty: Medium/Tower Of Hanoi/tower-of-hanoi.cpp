class Solution {
    void solve(int s, int d, int h, int n, int &cnt){
        cnt++;
        // Base Case
        if(n==1){
            return;
        }
        solve(s,h,d,n-1,cnt);
        solve(h,d,s,n-1,cnt);
        return;
        
    }
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        int cnt = 0;
        solve(from, to, aux, n, cnt);
        return cnt;
    }
};