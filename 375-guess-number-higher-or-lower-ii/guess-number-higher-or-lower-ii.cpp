class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        return f(1,n,dp);
    }

    int f(int i, int j, vector<vector<int>> &dp) {
        // base cases
        if(i == j) return 0; // if there is only one number for eg - 1, best strategy is to pick 0
        if(i+1 == j) return i; // if there are two numbers for eg - 1,2, best strategy is to pick the smaller one
        if(i+2 == j) return i+1; // if there are three numbers for eg - 1,2, best strategy is to pick the middle one

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;
        for(int k=i ; k<=j ; k++) {
            int ansIsOnLeft = k + f(i,k-1,dp);
            int ansIsOnRight = k + f(k+1,j,dp);

            ans = min(ans,max(ansIsOnLeft,ansIsOnRight)); // since we need to guarantee a win regardless of what no. we pick, we take max of ansIsOnLeft and ansIsOnRight
        }
        return dp[i][j] = ans;
    }
};