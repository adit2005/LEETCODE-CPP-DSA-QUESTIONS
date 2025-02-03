class Solution {
public:
    int maximizeWin(vector<int>& A, int k) {
        int res = 0, n = A.size(), j = 0;
        vector<int> dp(n + 1,
                       0); // dp[i] stores the max segment length up to index i

        for (int i = 0; i < n; ++i) {
            // Move `j` forward until A[i] - A[j] <= k (ensuring valid segment)
            while (A[j] < A[i] - k)
                ++j;

            // Compute the maximum segment length ending at `i`
            dp[i + 1] = max(dp[i], i - j + 1);

            // Update the result: sum of current valid segment + best previous
            // non-overlapping segment
            res = max(res, i - j + 1 + dp[j]);
        }
        return res;
    }
};
