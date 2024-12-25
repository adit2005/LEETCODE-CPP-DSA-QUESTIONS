class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        vector<int> dp(1 << n, -1); // DP table for bitmask states
        return solve(strength, k, 0, 1, dp);
    }

private:
    // Helper function for recursive backtracking with memoization
    int solve(vector<int>& strength, int k, int mask, int factor, vector<int>& dp) {
        int n = strength.size();
        if (mask == (1 << n) - 1) return 0; // All locks are broken
        if (dp[mask] != -1) return dp[mask]; // Return cached result

        int minTime = INT_MAX;

        // Try breaking each unbroken lock
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) { // If lock `i` is not broken
                int timeToBreak = (strength[i] + factor - 1) / factor; // Calculate time
                int newMask = mask | (1 << i); // Mark lock `i` as broken
                minTime = min(minTime, timeToBreak + solve(strength, k, newMask, factor + k, dp));
            }
        }

        dp[mask] = minTime; // Cache result
        return minTime;
    }
};
