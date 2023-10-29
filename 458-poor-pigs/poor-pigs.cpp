class Solution {
public:
    int poorPigs(int n, int d, int t) {
        int cnt = t/d;
        cnt++;
        int ans = 0;
        int x = 1;
        while(x < n){
             x *= cnt;
            ans++;
        }
        return ans;
    }
};