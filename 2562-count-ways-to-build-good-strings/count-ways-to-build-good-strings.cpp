class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int len, int& lo, int& hi, int& zero, int& one, vector<int>& dp){
        // base case
        if(len > hi) return 0;
        
        if(dp[len] != -1) return dp[len];
        int ans = 0;
        if(len >= lo) ans++;

        // add zero
        ans = (ans + solve(len + zero, lo, hi, zero, one, dp)) % mod;
        // add one
        ans = (ans + solve(len + one, lo, hi, zero, one, dp)) % mod;
        return dp[len] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high +1, -1);
        return solve(0, low, high, zero, one, dp);
    }
};