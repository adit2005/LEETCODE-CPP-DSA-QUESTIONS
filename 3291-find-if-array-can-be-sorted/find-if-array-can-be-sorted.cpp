
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        // Helper function to count set bits
        auto countSetBits = [](int num) -> int {
            return __builtin_popcount(num);
        };

        int start = 0;
        while (start < n) {
            int bitCount = countSetBits(nums[start]);
            int end = start;

            // Find the end of the current segment where all elements have the same bit count
            while (end + 1 < n && countSetBits(nums[end + 1]) == bitCount) {
                ++end;
            }

            // Sort this segment
            sort(nums.begin() + start, nums.begin() + end + 1);

            // Move to the next segment
            start = end + 1;
        }

        // Verify if the entire array is now sorted
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        return true;
    }
};