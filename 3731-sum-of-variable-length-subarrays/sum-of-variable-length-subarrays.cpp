class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0); // Prefix sum array with 1-based indexing
        
        // Step 1: Calculate prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int totalSum = 0;

        // Step 2: Traverse each index and calculate subarray sum using prefix sum
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]); // Find the starting index of the subarray
            totalSum += prefix[i + 1] - prefix[start]; // Calculate the sum of subarray using prefix
        }

        return totalSum; // Return the total sum of all subarrays
    }
};
