class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Prefix sums to quickly calculate sum of subarrays
        vector<double> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // dp[i][j] will store the maximum sum of averages for the first i elements with j partitions
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));
        
        // Base case: one partition, the average of the subarray
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = prefixSum[i] / i;
        }
        
        // Fill the dp array
        for (int j = 2; j <= k; ++j) { // Number of partitions
            for (int i = 1; i <= n; ++i) { // Number of elements considered
                for (int p = 0; p < i; ++p) { // Possible partition points
                    dp[i][j] = max(dp[i][j], dp[p][j - 1] + (prefixSum[i] - prefixSum[p]) / (i - p));
                }
            }
        }
        
        return dp[n][k];
    }
};
