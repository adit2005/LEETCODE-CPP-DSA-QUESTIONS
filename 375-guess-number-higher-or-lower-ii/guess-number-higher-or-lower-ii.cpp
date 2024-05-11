class Solution {
public:
    int getMoneyAmount(int n) {
        // Initialize a 2D vector to store the minimum cost of guessing a number
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Iterate over all possible lengths of subranges
        for (int len = 2; len <= n; ++len) {
            // Iterate over all possible starting points of subranges
            for (int begin = 1; begin <= n - len + 1; ++begin) {
                // Calculate the end point of the current subrange
                int end = begin + len - 1;
                
                // Iterate over all possible numbers to guess within the current subrange
                for (int i = begin; i <= end; ++i) {
                    int numPicked = i; // Number picked for guessing
                    
                    // If the number picked is the first number in the subrange
                    if (i == begin) {
                        // Calculate the cost of guessing the first number
                        dp[begin][end] = numPicked + dp[begin + 1][end];
                    } else if (i == end) {
                        // If the number picked is the last number in the subrange
                        dp[begin][end] = min(dp[begin][end], dp[begin][end - 1] + numPicked);
                    } else {
                        // Otherwise, calculate the minimum cost between two options:
                        // 1. Guessing a number before the current position
                        // 2. Guessing a number after the current position
                        dp[begin][end] = min(dp[begin][end], max(dp[begin][i - 1], dp[i + 1][end]) + numPicked);
                    }
                }
            }
        }

        // Return the minimum cost of guessing a number in the range [1, n]
        return dp[1][n];
    }
};
