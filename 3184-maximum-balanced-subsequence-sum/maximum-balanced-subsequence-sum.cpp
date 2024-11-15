class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        // `m` is a map used to store the maximum sum for balanced subsequences ending with a 
        // specific "key", which is the difference (nums[i] - i).
        // Initial value in the map: {INT_MIN, 0}, representing a dummy starting point.
        map<int, long long> m{{INT_MIN, 0}};

        // Iterate through the array to process each element.
        for (int i = 0; i < nums.size(); ++i) {
            // Find the first key in the map that is strictly greater than (nums[i] - i).
            auto it = m.upper_bound(nums[i] - i);

            // Calculate the maximum sum for a subsequence that includes nums[i].
            // The maximum sum is:
            //   - nums[i]: The current value.
            //   - prev(it)->second: The maximum sum of a valid subsequence ending with a
            //     difference smaller than or equal to (nums[i] - i).
            //   - max(0LL, ...): Ensures non-negative contributions from previous sums.
            long long sum = nums[i] + max(0LL, prev(it)->second);

            // Insert or update the current key (nums[i] - i) with the computed sum.
            // `insert_or_assign`: If (nums[i] - i) already exists, update its value;
            // otherwise, insert a new entry.
            m.insert_or_assign(it, nums[i] - i, sum);

            // Cleanup phase: Remove all keys in the map that have a sum less than or equal
            // to the current sum. This ensures that the map always retains only the most
            // optimal (maximum sum) subsequences for each key.
            for (; it != end(m) && it->second <= sum;) {
                m.erase(it++);  // Erase suboptimal entries.
            }
        }

        // The largest value in the map corresponds to the maximum sum of a balanced
        // subsequence in the array. Return this value.
        return rbegin(m)->second;
    }
};
