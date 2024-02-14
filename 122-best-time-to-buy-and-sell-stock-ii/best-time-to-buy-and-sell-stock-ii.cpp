class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        vector<vector<long>> dp(n + 1, vector<long>(2, -1));

        dp[n][0] = dp[n][1] = 0;

        long profit;

        for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    
    return dp[0][0];
    }
};