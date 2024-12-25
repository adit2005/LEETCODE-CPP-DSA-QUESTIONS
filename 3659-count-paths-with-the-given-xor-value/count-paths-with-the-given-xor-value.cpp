class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(int i, int j, int curr, vector<vector<int>>& grid, int k, vector<vector<unordered_map<int, int>>>& memo) {
        int m = grid.size();
        int n = grid[0].size();

        // Base case: If we reach the bottom-right cell
        if (i == m - 1 && j == n - 1) {
            return (curr == k) ? 1 : 0;
        }

        // Check if result is already computed
        if (memo[i][j].count(curr)) {
            return memo[i][j][curr];
        }

        int paths = 0;

        // Move right
        if (j + 1 < n) {
            paths = (paths + dfs(i, j + 1, curr ^ grid[i][j + 1], grid, k, memo)) % MOD;
        }

        // Move down
        if (i + 1 < m) {
            paths = (paths + dfs(i + 1, j, curr ^ grid[i + 1][j], grid, k, memo)) % MOD;
        }

        // Store result in memo
        return memo[i][j][curr] = paths;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Memoization table
        vector<vector<unordered_map<int, int>>> memo(m, vector<unordered_map<int, int>>(n));

        // Start DFS from the top-left corner
        return dfs(0, 0, grid[0][0], grid, k, memo);
    }
};
