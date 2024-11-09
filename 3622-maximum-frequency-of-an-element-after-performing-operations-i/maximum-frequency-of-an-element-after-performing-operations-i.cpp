class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ops) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: Count initial frequencies
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxFreq = 0;
        int n = nums.size();

        // Step 3: Iterate over potential target values from nums[0] to nums[n-1] + k + 1
        for (int i = nums[0]; i <= nums[n - 1] + k; ++i) {
            // Step 4: Find range of elements within [-k, k] of target
            auto lower = lower_bound(nums.begin(), nums.end(), i - k) - nums.begin();
            auto upper = upper_bound(nums.begin(), nums.end(), i + k) - nums.begin() - 1;

            // Step 5: Calculate maximum frequency for this target
            int achievableFreq = freqMap[i] + (int)min((long long)(upper - lower + 1 - freqMap[i]), (long long)ops);
            maxFreq = max(maxFreq, achievableFreq);
        }

        return maxFreq;
    }
};
