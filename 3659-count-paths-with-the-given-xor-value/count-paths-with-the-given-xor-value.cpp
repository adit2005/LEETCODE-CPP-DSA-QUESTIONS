class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // DP table: dp[i][j][xor_val] stores the number of paths ending at (i, j) with XOR value = xor_val
        vector<vector<unordered_map<int, int>>> dp(m, vector<unordered_map<int, int>>(n));

        // Initialize the starting cell
        dp[0][0][grid[0][0]] = 1;

        // Fill the DP table
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto& [xor_val, count] : dp[i][j]) {
                    // Move down
                    if (i + 1 < m) {
                        int new_xor = xor_val ^ grid[i + 1][j];
                        dp[i + 1][j][new_xor] = (dp[i + 1][j][new_xor] + count) % MOD;
                    }
                    // Move right
                    if (j + 1 < n) {
                        int new_xor = xor_val ^ grid[i][j + 1];
                        dp[i][j + 1][new_xor] = (dp[i][j + 1][new_xor] + count) % MOD;
                    }
                }
            }
        }

        // Return the number of paths reaching (m-1, n-1) with XOR value = k
        return dp[m - 1][n - 1][k];
    }
};
