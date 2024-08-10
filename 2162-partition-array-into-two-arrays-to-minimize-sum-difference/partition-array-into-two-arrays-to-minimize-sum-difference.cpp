class Solution {
public:
    // This function computes the minimum difference between the sums of two subsets
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1), right(n + 1);

        // Generate all possible subset sums for both halves of the array
        for (int i = 0; i < pow(2, n); i++) {
            int ctr = 0;  // Counter to track the number of elements taken in the subset
            int a = 0, b = 0; // 'a' accumulates sums from the first half, 'b' from the second half
            for (int j = 0; j < n; j++) {
                if (1 << j & i) {  // Check if the j-th bit in 'i' is set (bitmasking)
                    ctr++;  // Increment the counter when the j-th element is included in the subset
                    a += nums[j];  // Add the corresponding element from the first half
                    b += nums[n + j];  // Add the corresponding element from the second half
                }
            }
            // Store the sum of 'ctr' elements in the corresponding bucket
            left[ctr].push_back(a);
            right[ctr].push_back(b);
        }

        // Sort all possible subset sums from the second half for binary search
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        // Calculate the total sum of the entire array by using the full subset sums from both halves
        int tot = left[n][0] + right[n][0]; // This sum is obtained by taking all n elements from both halves
        int ans = INT_MAX;  // Initialize the minimum difference to a large value

        // Iterate through all possible subsets of the first half
        for (int i = 0; i <= n; i++) {
            for (int l : left[i]) {  // Iterate over all possible sums with 'i' elements in the first half
                // We need to find the best complementing subset sum from the second half to minimize the difference
                int ind = lower_bound(right[n - i].begin(), right[n - i].end(), (ceil(tot / 2.0) - l)) - right[n - i].begin();
                
                // If a valid complementing sum is found, compute the total sum of the subset pair
                if (ind < right[n - i].size()) {
                    int a = l + right[n - i][ind];
                    ans = min(ans, abs(2 * a - tot)); // Update the minimum difference
                }
            }
        }
        return ans; // Return the minimum difference found
    }
};
