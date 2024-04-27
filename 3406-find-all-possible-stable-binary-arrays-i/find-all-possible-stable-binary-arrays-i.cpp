class Solution {
public:
    int MOD = 1e9 + 7;
    int limit;
    vector<vector<vector<vector<int>>>> dp;
    
    int f(int z, int o, int prev, int cons){
        if(z<0 || o<0 || cons > limit) return 0;
        if(z==0 && o==0) return 1;
        
        if(dp[z][o][prev][cons] != -1) return dp[z][o][prev][cons];
        int res = 0;
        
        if(prev==0){
            int a = f(z-1, o, 0, cons+1);
            int b = f(z, o-1, 1, 1);
            
            res = (a+b)%MOD;
        }
        else{
            int a = f(z-1, o, 0, 1);
            int b = f(z, o-1, 1, cons+1);
            
            res = (a+b)%MOD;
        }
        
        return dp[z][o][prev][cons] = res;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        this->limit = limit;
        dp = vector<vector<vector<vector<int>>>>(zero+1,vector<vector<vector<int>>>(one+1, vector<vector<int>>(2, vector<int>(limit+1, -1))));

        int a = f(zero, one-1, 1, 1);
        int b = f(zero-1, one, 0, 1);
        
        return (a+b)%MOD;
    }
};