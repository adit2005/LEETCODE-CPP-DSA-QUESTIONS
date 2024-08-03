class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> indices; // To store indices of all 1s
        
        // Collect indices of all 1s
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                indices.push_back(i);
            }
        }
        
        int n = indices.size();
        if (k > n) return -1; // If there are fewer than k 1s, it's not possible
        
        vector<long long> prefixSum(n + 1, 0); // Prefix sum array
        
        // Compute prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + indices[i];
        }
        
        long long result = LLONG_MAX; // Initialize result to maximum possible value
        
        for (int i = 0; i <= n - k; ++i) {
            int mid = i + k / 2;
            long long leftCost = (long long)indices[mid] * (mid - i) - (prefixSum[mid] - prefixSum[i]);
            long long rightCost = (prefixSum[i + k] - prefixSum[mid + 1]) - (long long)indices[mid] * (i + k - mid - 1);
            result = min(result, leftCost + rightCost);
        }
        
        // Adjust the result by subtracting the minimum number of moves
        result -= (long long)(k / 2) * ((k + 1) / 2);
        
        return result; // Return result as int
    }
};
