class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // Difference array for range updates

        // Step 1: Process each query and mark increments in the difference array
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            diff[l] += 1;          // Increment start of the range
            if (r + 1 < n) diff[r + 1] -= 1; // Decrement end of the range + 1
        }

        // Step 2: Compute the actual prefix sums to find the increments for each index
        vector<int> increments(n, 0);
        increments[0] = diff[0];
        for (int i = 1; i < n; ++i) {
            increments[i] = increments[i - 1] + diff[i];
        }

        // Step 3: Check if the increments are valid for the original array
        for (int i = 0; i < n; ++i) {
            if (increments[i] < nums[i]) {
                return false; // If increments exceed the original value, not possible
            }
        }

        return true; // All conditions satisfied
    }
};
