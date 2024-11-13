#include <vector>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Check for consecutive increasing subarrays of length `k`
        vector<bool> isIncreasing(n, false);  // Mark positions where subarrays of length `k` are strictly increasing
        
        // Mark strictly increasing subarrays of length `k`
        for (int i = 0; i <= n - k; ++i) {
            bool strictlyIncreasing = true;
            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j] >= nums[j + 1]) {  // If not strictly increasing, break
                    strictlyIncreasing = false;
                    break;
                }
            }
            if (strictlyIncreasing) {
                isIncreasing[i] = true;
            }
        }

        // Now check for two adjacent strictly increasing subarrays
        for (int i = 0; i <= n - 2 * k; ++i) {
            if (isIncreasing[i] && isIncreasing[i + k]) {  // Adjacent subarrays of length `k`
                return true;
            }
        }
        
        return false;  // No such adjacent increasing subarrays found
    }
};
