class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // Declare dp and suffixMax arrays
        vector<vector<int>> dp(301, vector<int>(301, 0));
        vector<vector<int>> suffixMax(301, vector<int>(301, 0));

        int ans = 1;

        for (int num : nums) {
            if (dp[num][0] < 1) {
                dp[num][0] = 1;
            }

            for (int prevNum = 1; prevNum <= 300; prevNum++) {
                int dNew = abs(num - prevNum);
                int bestChain = suffixMax[prevNum][dNew];

                if (bestChain > 0) {
                    // Continue the chain
                    dp[num][dNew] = max(dp[num][dNew], bestChain + 1);
                } else {
                    // Fresh chain, but prevNum should exist
                    if (suffixMax[prevNum][0] > 0) {
                        dp[num][dNew] = max(dp[num][dNew], 2);
                    }
                }

                ans = max(ans, dp[num][dNew]);
            }

            // Update suffixMax for the current num
            suffixMax[num][299] = dp[num][299];
            for (int d = 298; d >= 0; d--) {
                suffixMax[num][d] = max(suffixMax[num][d + 1], dp[num][d]);
            }
        }

        return ans;
    }
};
