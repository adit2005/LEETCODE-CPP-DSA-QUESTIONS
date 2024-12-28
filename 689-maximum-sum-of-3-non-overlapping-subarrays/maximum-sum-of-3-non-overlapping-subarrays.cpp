class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Calculate prefix sums
        // The prefixSum array allows us to calculate the sum of any subarray in O(1) time.
        // prefixSum[i] represents the sum of the first i elements of the array.
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Step 2: Initialize dynamic programming tables
        // `bestSum[x][y]` represents the maximum sum we can achieve using `x` subarrays
        // considering the first `y` elements of the array.
        // `bestIndex[x][y]` stores the starting index of the last subarray that contributes
        // to `bestSum[x][y]`.
        vector<vector<int>> bestSum(4, vector<int>(n + 1, 0));
        vector<vector<int>> bestIndex(4, vector<int>(n + 1, 0));

        // Step 3: Compute the best sum and indices for 1, 2, and 3 subarrays
        for (int subarrayCount = 1; subarrayCount <= 3; subarrayCount++) {
            for (int endIndex = k * subarrayCount; endIndex <= n; endIndex++) {
                // Calculate the sum of the current subarray of length `k` ending at `endIndex`.
                int currentSum = prefixSum[endIndex] - prefixSum[endIndex - k] +
                                 bestSum[subarrayCount - 1][endIndex - k];

                // Check if including the current subarray gives a better sum.
                if (currentSum > bestSum[subarrayCount][endIndex - 1]) {
                    // Update the best sum and store the starting index of the current subarray.
                    bestSum[subarrayCount][endIndex] = currentSum;
                    bestIndex[subarrayCount][endIndex] = endIndex - k;
                } else {
                    // Otherwise, carry forward the previous best sum and index.
                    bestSum[subarrayCount][endIndex] = bestSum[subarrayCount][endIndex - 1];
                    bestIndex[subarrayCount][endIndex] = bestIndex[subarrayCount][endIndex - 1];
                }
            }
        }

        // Step 4: Trace back the starting indices of the three subarrays
        vector<int> result(3, 0);
        int currentEnd = n;  // Start from the end of the array
        for (int subarrayIndex = 3; subarrayIndex >= 1; subarrayIndex--) {
            // Retrieve the starting index of the last subarray contributing to the best sum
            result[subarrayIndex - 1] = bestIndex[subarrayIndex][currentEnd];
            currentEnd = result[subarrayIndex - 1];  // Move to the previous subarray
        }

        return result;
    }
};
