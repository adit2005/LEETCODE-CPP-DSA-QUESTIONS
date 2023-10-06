class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
        return std::vector<int>();
    }

    // Sort the input array in ascending order.
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    
    // Initialize two arrays to keep track of the maximum subset size ending at index i
    // and the last index that divides nums[i].
    std::vector<int> dp(n, 1);
    std::vector<int> prev(n, -1);

    int max_len = 1;  // Length of the largest divisible subset.
    int max_idx = 0;  // Index of the last element in the largest divisible subset.

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    // Reconstruct the largest divisible subset.
    std::vector<int> result;
    while (max_idx != -1) {
        result.push_back(nums[max_idx]);
        max_idx = prev[max_idx];
    }

    return result;
    }
};