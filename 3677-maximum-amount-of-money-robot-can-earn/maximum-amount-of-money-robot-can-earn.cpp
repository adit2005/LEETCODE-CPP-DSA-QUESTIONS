class Solution {
private:
    // Helper function for recursive DFS with memoization
    int dfs(int i, int j, int neutralizations, vector<vector<vector<int>>>& dp, vector<vector<int>>& coins, int m, int n) {
        // Base case: If out of bounds, return INT_MIN
        if (i >= m || j >= n) return INT_MIN;

        // Base case: If at the bottom-right corner
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && neutralizations > 0) {
                return 0; // Neutralize the robber here
            }
            return coins[i][j]; // Gain or lose coins directly
        }

        // If already computed
        if (dp[i][j][neutralizations] != INT_MIN) {
            return dp[i][j][neutralizations];
        }

        int maxCoins = INT_MIN;

        // If current cell value is positive
        if (coins[i][j] >= 0) {
            int down = dfs(i + 1, j, neutralizations, dp, coins, m, n);
            int right = dfs(i, j + 1, neutralizations, dp, coins, m, n);
            maxCoins = coins[i][j] + max(down, right);
        } 
        // If current cell value is negative
        else {
            // Case 1: Neutralize the robber (if neutralizations are available)
            if (neutralizations > 0) {
                int downNeutralized = dfs(i + 1, j, neutralizations - 1, dp, coins, m, n);
                int rightNeutralized = dfs(i, j + 1, neutralizations - 1, dp, coins, m, n);
                maxCoins = max(maxCoins, max(downNeutralized, rightNeutralized));
            }
            // Case 2: Do not neutralize the robber
            int down = dfs(i + 1, j, neutralizations, dp, coins, m, n);
            int right = dfs(i, j + 1, neutralizations, dp, coins, m, n);
            maxCoins = max(maxCoins, coins[i][j] + max(down, right));
        }

        // Store result in memoization table
        return dp[i][j][neutralizations] = maxCoins;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        // Memoization table: dp[i][j][neutralizations] stores the max coins from (i, j) with `neutralizations` left
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        // Start from the top-left corner with 2 neutralizations
        return dfs(0, 0, 2, dp, coins, m, n);
    }
};
