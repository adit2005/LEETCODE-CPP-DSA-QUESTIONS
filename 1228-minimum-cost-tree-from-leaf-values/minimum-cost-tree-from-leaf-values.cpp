class Solution {
public:
    int memo[41][41]; // Memoization table to store the minimum costs.
    int maxi[41][41]; // Table to store the precomputed maximum values for subarrays.
    
    // Recursive function to find the minimum cost of merging elements from 'left' to 'right'.
    int dp(int left, int right) {
        if (left == right) return 0; // Base case: a single leaf node, so no cost.
        
        // If the value has already been computed, return it to save time.
        if (memo[left][right] != -1) return memo[left][right];
        
        int ans = 1 << 30; // Initialize 'ans' to a large value (infinity-like) to find the minimum.
        
        // Try every possible partition point 'i' between 'left' and 'right'.
        for (int i = left; i < right; i++) {
            // Calculate the cost of this partition:
            // - maxi[left][i]: max in the left subarray
            // - maxi[i+1][right]: max in the right subarray
            // - dp(left, i): cost of merging the left subarray
            // - dp(i+1, right): cost of merging the right subarray
            ans = min(ans, maxi[left][i] * maxi[i+1][right] + dp(left, i) + dp(i+1, right));
        }
        
        // Store the computed result in the memoization table.
        memo[left][right] = ans;
        return ans; // Return the minimum cost.
    }
    
    // Main function to compute the minimum cost tree from leaf values.
    int mctFromLeafValues(vector<int>& arr) {
        memset(memo, -1, sizeof(memo)); // Initialize the memo table with -1 (indicating uncomputed states).
        
        // Precompute the maximum values for all subarrays.
        for (int i = 0; i < arr.size(); i++) {
            maxi[i][i] = arr[i]; // The max value of a single element is the element itself.
            for (int j = i + 1; j < arr.size(); j++) {
                // Calculate the maximum value for the subarray from 'i' to 'j'.
                maxi[i][j] = max(maxi[i][j - 1], arr[j]);
            }
        }
        
        // Call the dp function for the entire range [0, arr.size() - 1].
        return dp(0, arr.size() - 1);
    }
};
