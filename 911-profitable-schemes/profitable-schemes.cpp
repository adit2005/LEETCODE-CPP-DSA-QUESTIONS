class Solution {
public:
    static constexpr int MOD = 1'000'000'007; // Define a constant for modulo operation to prevent overflow

    // Function to calculate the number of profitable schemes
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // Initialize a 2D DP table with dimensions (n+1) x (minProfit+1)
        // dp[i][j] represents the number of schemes using i members to achieve at least j profit
        vector<vector<int>> dp(n+1, vector<int>(minProfit+1));
        auto new_dp = dp; // A temporary DP table used for updating

        // Base case: For any number of members, the number of ways to achieve 0 profit is 1 (by doing nothing)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Iterate over each group (in reverse order)
        for (int i = 0 ; i < group.size(); i++) {
            // Iterate over each number of members
            for (int j = 0; j <= n; j++) {
                // Iterate over each profit value
                for (int p = 0; p <= minProfit; p++) {
                    int not_taken = dp[j][p]; // Case where the current group is not taken
                    int taken = 0;
                    // Case where the current group is taken (only if enough members are available)
                    if (group[i] <= j) {
                        taken = dp[j - group[i]][max(0, p - profit[i])];
                    }
                    // Update the temporary DP table with the sum of both cases, modulo MOD
                    new_dp[j][p] = (taken + not_taken) % MOD;
                }
            }
            // Swap the temporary DP table with the main DP table for the next iteration
            swap(dp, new_dp);
        }

        // Return the number of schemes using exactly n members to achieve at least minProfit profit
        return dp[n][minProfit];
    }
};
