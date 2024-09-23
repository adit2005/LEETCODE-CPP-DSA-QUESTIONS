class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Create prefix sum array `pre`
        // `pre[i]` stores the sum of elements from nums[0] to nums[i-1].
        vector<long long> pre(n + 1);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        
        // Step 2: Initialize a dp array where `dp[i]` is a pair.
        // The first element of `dp[i]` stores the max length of valid subarrays up to index i.
        // The second element of `dp[i]` stores the minimum sum associated with the last valid subarray of that length.
        vector<pair<int, long long>> dp(n + 1);
        for (int i = 0; i <= n; i++) {
            dp[i] = {0, 1e18};  // Initially, all subarrays have length 0 and sum as infinity.
        }
        
        dp[0] = {0, 0};  // Base case: no elements, so length is 0 and sum is 0.
        
        // Step 3: Iterate through the array and build up the dp table.
        for (int i = 1; i <= n; i++) {
            // Get the sum from dp[i-1].second (this represents the sum of the last valid subarray up to i-1)
            long long prevSum = dp[i-1].second;
            
            // Calculate the "needed" sum for the next subarray.
            // This is the sum of all elements up to i-1 plus the sum of the last valid subarray.
            long long needed = pre[i-1] + prevSum;

            // Step 4: Binary search to find the smallest index where the prefix sum
            // is greater than or equal to the "needed" sum.
            int low = i, high = n, where = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                
                // If the prefix sum at `mid` is greater than or equal to the needed sum, 
                // record `mid` and try for a smaller index by adjusting `high`.
                if (pre[mid] >= needed) {
                    where = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            // Step 5: If we find such a valid `where`, we update dp[where] with the new values.
            if (where != -1) {
                pair<int, long long> p = {dp[i-1].first + 1, pre[where] - pre[i-1]};  // Create the new pair.
                
                // If the new subarray length is greater, or if the length is the same but the sum is smaller, update dp[where].
                if (dp[where].first < dp[i-1].first + 1) {
                    dp[where] = p;
                } else if (dp[where].first == dp[i-1].first + 1) {
                    dp[where].second = std::min(dp[where].second, pre[where] - pre[i-1]);
                }
            }
            
            // Step 6: Update dp[i] by extending the subarray from dp[i-1].
            // We check if extending the previous subarray gives us a better (or same) solution.
            if (dp[i].first < dp[i-1].first) {
                dp[i] = {dp[i-1].first, dp[i-1].second + pre[i] - pre[i-1]};
            } else if (dp[i].first == dp[i-1].first) {
                dp[i].second = min(dp[i].second, pre[i] - pre[i-1] + dp[i-1].second);
            }
        }

        // Step 7: Extract the maximum length from the dp array.
        int ans = 0;
        for (auto &[len, su] : dp) {
            ans = max(ans, len);
        }
        
        return ans;
    }
};
