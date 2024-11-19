class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freq; // To track frequency of elements
    long long currentSum = 0, maxSum = 0;

    // Initialize the sliding window
    for (int i = 0; i < nums.size(); ++i) {
        // Add the current element to the window
        currentSum += nums[i];
        freq[nums[i]]++;

        // Maintain the window size
        if (i >= k) {
            currentSum -= nums[i - k];
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0) {
                freq.erase(nums[i - k]);
            }
        }

        // Check if the current window is valid (distinct elements)
        if (freq.size() == k) {
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}
};