class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int b_count = 0;

        // dp[i]: The number of deletions required to
        // balance the substring s[0, i)
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                dp[i + 1] = dp[i];
                b_count++;
            } else {
                // Two cases: remove 'a' or keep 'a'
                dp[i + 1] = min(dp[i] + 1, b_count);
            }
        }

        return dp[n];
    }
};