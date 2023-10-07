class Solution {
public:
    int dp[2097152];  // dp array to memoize the results for different states
    bool solve(int m, int d, int mask) {
        if (d <= 0) {
            return false;  // If desiredTotal is less than or equal to 0, the current player loses.
        }
        if (dp[mask] != -1) {
            return dp[mask];  // If this state has been calculated before, return the result.
        }
        for (int i = 1; i <= m; i++) {
            if ((mask & (1 << i)) == 0 && solve(m, d - i, mask | (1 << i)) == false) {
                // If the number i is not chosen yet (bit i is 0 in mask) and the opponent can't win from the new state.
                return dp[mask] = true;  // The current player wins from this state.
            }
        }
        return dp[mask] = false;  // If no winning move is found, the current player loses.
    }
    bool canIWin(int m, int d) {
        if (d <= m) {
            return true;  // If desiredTotal is less than or equal to the maximum choosable integer, the first player wins.
        }
        if ((m * (m + 1)) / 2 < d) {
            return false;  // If the sum of all integers from 1 to m is less than desiredTotal, the first player can't win.
        }
        memset(dp, -1, sizeof(dp));  // Initialize dp array with -1 to indicate uncalculated states.
        return solve(m, d, 0);  // Call the solve function with initial parameters.
    }
};
