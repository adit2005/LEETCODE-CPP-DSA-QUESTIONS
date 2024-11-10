class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // `one` vector keeps track of the count of set bits (1s) for each bit position (0 to 31)
        vector<int> one(32, 0);
        
        int i = 0;           // Start pointer of the sliding window
        int ans = 1e9;       // Initialize answer with a large value (infinity equivalent)
        
        for (int j = 0; j < nums.size(); j++) {  // `j` is the end pointer of the sliding window
            // Update the count of set bits in the `one` vector for the current `nums[j]`
            for (int bit = 0; bit < 32; bit++) {
                if (nums[j] & (1 << bit)) one[bit]++;
            }
            
            // Calculate the current `num` as the value represented by the set bits in `one`
            long num = 0;
            for (int bit = 0; bit < 32; bit++) {
                if (one[bit]) num += (long)pow(2, bit);
            }
            
            // Shrink the window from the left (`i`) while the subarray bitwise OR is greater than or equal to `k`
            while (num >= k && i <= j) {
                // Update the minimum length if the current window `[i, j]` is smaller
                ans = min(ans, j - i + 1);
                
                // Now, remove the effect of `nums[i]` from `one` vector as `i` is about to move
                for (int bit = 0; bit < 32; bit++) {
                    if (nums[i] & (1 << bit)) one[bit]--;
                }
                
                // Recalculate `num` for the updated window after removing `nums[i]`
                long long newNum = 0;
                for (int bit = 0; bit < 32; bit++) {
                    if (one[bit]) newNum += (long)pow(2, bit);
                }
                
                num = newNum;  // Update `num` with the recalculated OR value for the new window
                i++;           // Move the left pointer of the window to the right
            }
        }
        
        // If `ans` is not updated, return -1 (no valid subarray found); otherwise, return the minimum length
        return ans == 1e9 ? -1 : ans;
    }
};
