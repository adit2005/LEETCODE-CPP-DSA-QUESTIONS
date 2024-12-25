class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int mod = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(20, 0)));

        // Base case: At destination (n-1, m-1)
        dp[n - 1][m - 1][grid[n - 1][m - 1] ^ k] = 1;

        // Fill the DP table in bottom-up manner (starting from bottom-right)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int curr = 0; curr < 16; curr++) {
                    if (i == n - 1 && j == m - 1) continue; // Skip the destination cell (already initialized)

                    int newCurr = curr ^ grid[i][j];

                    // Move right if within bounds
                    if (j + 1 < m) {
                        dp[i][j][curr] = (dp[i][j][curr] + dp[i][j + 1][newCurr]) % mod;
                    }

                    // Move down if within bounds
                    if (i + 1 < n) {
                        dp[i][j][curr] = (dp[i][j][curr] + dp[i + 1][j][newCurr]) % mod;
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};
