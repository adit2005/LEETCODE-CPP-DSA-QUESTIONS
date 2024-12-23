class Solution {
public:
    // Function to compute the minimum triangulation score for a subpolygon
    int helper(int i, int j, vector<int>& values, vector<vector<int>>& dp) {
        // Base case: If the number of vertices is less than 3, no triangulation possible
        if (j - i < 2) return 0;

        // If the result is already computed, return it from the dp table
        if (dp[i][j] != -1) return dp[i][j];

        int minScore = INT_MAX;

        // Try all possible third vertices k to form the triangle (i, k, j)
        for (int k = i + 1; k < j; k++) {
            // Score of the triangle (i, k, j)
            int triangleScore = values[i] * values[k] * values[j];
            // Recursively calculate the score for the sub-polygons (i, k) and (k, j)
            int leftScore = helper(i, k, values, dp);
            int rightScore = helper(k, j, values, dp);
            // Minimize the total score
            minScore = min(minScore, triangleScore + leftScore + rightScore);
        }

        // Store the computed result in the dp table
        return dp[i][j] = minScore;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // Memoization table to store minimum scores for sub-polygons
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Start the recursion for the entire polygon (0, n-1)
        return helper(0, n - 1, values, dp);
    }
};
