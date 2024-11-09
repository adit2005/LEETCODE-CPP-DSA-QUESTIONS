class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size(), ans = 0, left = 0, right = 0;
        sort(nums.begin(), nums.end());

        // HashMap to store the frequency of each number in the sorted array
        unordered_map<int, int> count;
        for(int num : nums) {
            count[num]++;
        }

        // First pass: choose an existing number as the "reference point"
        for(int mid = 0; mid < n; mid++) {
            // Move the left pointer to maintain that the difference between nums[mid] and nums[left] is <= k
            while(nums[mid] - nums[left] > k) {
                left++;
            }

            // Move the right pointer to maintain that the difference between nums[right] and nums[mid] is <= k
            while(right < n - 1 && nums[right + 1] - nums[mid] <= k) {
                right++;
            }

            int total = right - left + 1; // total elements in the current range
            ans = max(ans, min(total - count[nums[mid]], numOperations) + count[nums[mid]]);
        }

        // Second pass: choose a non-existent number as the "reference point"
        left = 0;
        for(right = 0; right < n; right++) {
            int mid = (nums[left] + nums[right]) / 2;

            // Move the left pointer until the mid-point falls within range [nums[left], nums[right]]
            while(mid - nums[left] > k || nums[right] - mid > k) {
                left++;
                mid = (nums[left] + nums[right]) / 2;
            }
            ans = max(ans, min(right - left + 1, numOperations));
        }

        return ans;
    }
};
