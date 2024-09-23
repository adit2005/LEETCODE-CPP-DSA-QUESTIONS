class Solution {
public:
    // Function to find the maximum length of a non-decreasing array
    int findMaximumLength(vector<int>& nums) {
        
        int n = nums.size();  // Get the size of the input array
        vector<long long> v(n+1, 0);  // Prefix sum array `v`, initialized to 0
        vector<int> dp(n+1, 0);  // DP array `dp`, where `dp[i]` stores the maximum length up to index `i`
        
        // Step 1: Build prefix sum array `v`
        for(int i = 1; i <= n; i++)
            v[i] = v[i-1] + nums[i-1];  // Calculate the cumulative sum of the elements in nums
        
        vector<vector<long long>> sk;  // Stack `sk` to store pairs of (prefix_sum_value, index)
        sk.push_back({0, 0});  // Initialize with {0, 0} to represent the base case (no elements considered yet)
        
        // Step 2: Iterate through the array and calculate the maximum length of non-decreasing subarrays
        for (int i = 1; i <= n; i++) {
            int low = 0, high = sk.size() - 1;  // Binary search boundaries
            int p = 0;  // `p` will store the best index found in the binary search
            
            // Binary search to find the largest `p` such that `sk[p][0] <= v[i]`
            while (low <= high) {
                int mid = low + (high - low) / 2;
                
                // Check if the prefix sum at `mid` is less than or equal to `v[i]`
                if (sk[mid][0] <= v[i]) {
                    p = max(p, mid);  // Update `p` with the valid index
                    low = mid + 1;  // Search in the right half
                } else {
                    high = mid - 1;  // Search in the left half
                }
            }
            
            int index = sk[p][1];  // Get the index of the subarray found by binary search
            
            // Step 3: Update dp[i] based on the best previous subarray
            dp[i] = dp[index] + 1;  // Extend the maximum length by including the new subarray
            
            // Calculate the sum for the next subarray using the current index
            long long add = 2 * v[i] - v[index];
            
            // Step 4: Maintain the stack such that it always has non-decreasing values of `add`
            while (sk.back()[0] >= add)
                sk.pop_back();  // Remove the elements from the stack that violate the non-decreasing order
            
            // Push the new pair {add, i} to the stack
            sk.push_back({add, i});
        }
        
        // Step 5: Return the maximum length of the non-decreasing subarray found
        return dp[n];
    }
};
