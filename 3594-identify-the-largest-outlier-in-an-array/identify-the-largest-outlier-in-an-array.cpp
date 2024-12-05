#include <unordered_map>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0); // Step 1: Calculate total sum
        unordered_map<int, int> freq; // Step 2: Store frequencies of elements

        for (int num : nums) {
            freq[num]++;
        }

        int max_outlier = INT_MIN;

        // Step 3: Iterate through each number
        for (int num : nums) {
            int x = (total_sum - num) / 2;

            // Check if the remaining sum is divisible by 2 and x exists in the map
            if ((total_sum - num) % 2 == 0 && freq[x] > 0) {
                // Temporarily reduce the frequency of the current outlier candidate
                if (x == num && freq[x] <= 1) continue;

                max_outlier = max(max_outlier, num);
            }
        }
        return max_outlier;
    }
};
