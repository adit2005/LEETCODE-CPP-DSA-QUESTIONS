class Solution {
public:
    // Function to find the maximum frequency score of an element after performing at most k increments.
    int maxFrequencyScore(vector<int>& nums, long long k) {
        // Sort the array.
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // Prefix sum array to store the sum of elements up to the i-th index.
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Using binary search to find the maximum size of the subsequence with the same value after k increments.
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            bool canForm = false; // Variable to check if a subsequence of size mid can be formed.

            // Check every subsequence of size mid.
            for (int i = 0; i <= n - mid; i++) {
                int newRight = i + mid;
                // Find the median value in the current subsequence.
                int medianValue = nums[(i + newRight) / 2];
                long long costLeft = ((i + newRight) / 2 - i) * (long long) medianValue - (prefixSum[(i + newRight) / 2] - prefixSum[i]);
                long long costRight = (prefixSum[newRight] - prefixSum[(i + newRight) / 2]) - ((newRight - (i + newRight) / 2) * (long long) medianValue);

                // Check if it's possible to make all the elements equal to medianValue with at most k increments.
                if (costLeft + costRight <= k) {
                    canForm = true; // It's possible; thus, mid is a feasible solution.
                    break;
                }
            }

            // Update the search range based on whether mid can be achieved.
            if (canForm) {
                left = mid; // The capacity to form a larger subsequence may exist.
            } else {
                right = mid - 1; // Decrease the size as mid cannot be formed.
            }
        }

        // Return the maximum size of the subsequence we found.
        return left;
    }
};
