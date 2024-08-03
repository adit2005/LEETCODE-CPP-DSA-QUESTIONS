class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> positionOfOnes; // Holds the positions of '1's in the input vector.
      
        // Extracting the positions of '1's from the input vector.
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                positionOfOnes.push_back(i);
            }
        }
      
        int totalOnes = positionOfOnes.size(); // The total number of '1's found.
        vector<long> prefixSum(totalOnes + 1, 0); // Prefix sum array for storing cumulative positions sum.

        // Computing the prefix sums of the positions of ones.
        for (int i = 0; i < totalOnes; ++i) {
            prefixSum[i + 1] = prefixSum[i] + positionOfOnes[i];
        }
      
        long minOperations = LONG_MAX; // Initialize minimum operations to a large value.
        int leftGroupSize = (k + 1) / 2; // Number of elements to the left of mid element in the current window.
        int rightGroupSize = k - leftGroupSize; // Number of elements to the right
      
        // Sliding window over the array of ones to find minimum moves.
        for (int i = leftGroupSize - 1; i < totalOnes - rightGroupSize; ++i) {
            int current = positionOfOnes[i]; // The current position we are focusing on.
            long sumLeft = prefixSum[i + 1] - prefixSum[i + 1 - leftGroupSize];
            long sumRight = prefixSum[i + 1 + rightGroupSize] - prefixSum[i + 1];
          
            long operationsForLeft = ((current + current - leftGroupSize + 1L) * leftGroupSize / 2) - sumLeft;
            long operationsForRight = sumRight - ((current + 1L + current + rightGroupSize) * rightGroupSize / 2);
          
            // Update the minimum operations if the current moves are less.
            minOperations = min(minOperations, operationsForLeft + operationsForRight);
        }
      
        return minOperations; // Return the minimum number of operations found.
    }
};