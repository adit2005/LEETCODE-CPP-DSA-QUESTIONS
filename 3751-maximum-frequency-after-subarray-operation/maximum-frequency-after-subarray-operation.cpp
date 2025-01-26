class Solution {
public:
    int calculateMaxGain(const vector<int>& nums, int targetValue, int k) {
        int maxGain = 0, currentGain = 0;
        for (int num : nums) {
            if (num == k) currentGain--;
            if (num == targetValue) currentGain++;
            if (currentGain < 0) currentGain = 0;
            maxGain = max(maxGain, currentGain);
        }
        return maxGain;
    }

    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        int maxFrequency = 0;
        for (const auto& [value, _] : frequencyMap) {
            maxFrequency = max(maxFrequency, calculateMaxGain(nums, value, k));
        }
        return frequencyMap[k] + maxFrequency;
    }
};