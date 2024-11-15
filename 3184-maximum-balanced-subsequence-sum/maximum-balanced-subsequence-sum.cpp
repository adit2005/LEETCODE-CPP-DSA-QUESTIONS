#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long inf = 1e9 + 7; // Large constant for negative infinity

// Binary Indexed Tree (BIT) implementation for range queries and point updates
class BIT {
    vector<long long> bit;
public:
    BIT(int size) : bit(size + 1, -inf) {}

    // Query the maximum value in the range [1, idx]
    long long pre_max(int idx) {
        idx += 1; // BIT uses 1-based indexing
        long long ans = -inf;
        while (idx > 0) {
            ans = max(ans, this->bit[idx]);
            idx -= idx & -idx; // Move to parent node
        }
        return ans;
    }

    // Update the BIT by setting the value at index 'idx' to the maximum of the current value and 'val'
    void update(int idx, long long val) {
        idx += 1; // BIT uses 1-based indexing
        while (idx < this->bit.size()) {
            this->bit[idx] = max(this->bit[idx], val);
            idx += idx & -idx; // Move to parent node
        }
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        vector<int> mapping;
        int n = nums.size();

        // Step 1: Preprocess the nums array by subtracting indices from the values
        for (int i = 0; i < n; ++i) {
            mapping.push_back(nums[i] - i);
        }

        // Step 2: Sort the mapping and remove duplicates
        sort(mapping.begin(), mapping.end());
        mapping.erase(unique(mapping.begin(), mapping.end()), mapping.end());

        // Step 3: Initialize the BIT for tracking the maximum values
        BIT bit(n);
        long long ans = -inf; // To store the maximum balanced subsequence sum

        // Step 4: Iterate over the array, and use the BIT to compute the maximum sum
        for (int i = 0; i < n; ++i) {
            int &x = nums[i];

            // Step 5: Find the index in the mapping for the current value (nums[i] - i)
            int j = lower_bound(mapping.begin(), mapping.end(), x - i) - mapping.begin();

            // Step 6: Compute the current sum by querying the BIT for the maximum sum at previous indices
            long long cur = max(bit.pre_max(j) + x, (long long)x);
            
            // Step 7: Update the answer with the maximum sum encountered
            ans = max(ans, cur);

            // Step 8: Update the BIT with the new computed value at index j
            bit.update(j, cur);
        }

        // Step 9: Return the final result which is the maximum balanced subsequence sum
        return ans;
    }
};


