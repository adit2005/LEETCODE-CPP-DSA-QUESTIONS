class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        
        dp[0] = 1; // Base case: There's exactly one way to make a string of length 0.

        for (int len = 1; len <= high; len++) {
            // Add contributions from adding 'zero' and 'one'
            if (len >= zero) {
                dp[len] = (dp[len] + dp[len - zero]) % mod;
            }
            if (len >= one) {
                dp[len] = (dp[len] + dp[len - one]) % mod;
            }
        }

        // Sum up all good strings in the range [low, high]
        int result = 0;
        for (int len = low; len <= high; len++) {
            result = (result + dp[len]) % mod;
        }

        return result;
    }
};
