#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());  // Sort the array
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            int min_target = lower - nums[i];
            int max_target = upper - nums[i];
            
            // Find the range [min_target, max_target] using two-pointer range
            auto low = std::lower_bound(nums.begin() + i + 1, nums.end(), min_target);
            auto high = std::upper_bound(nums.begin() + i + 1, nums.end(), max_target);
            
            count += (high - low);  // Count of elements in the range
        }
        
        return count;
    }
};
