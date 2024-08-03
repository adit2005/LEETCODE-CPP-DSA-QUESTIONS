class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positive = 0, negative = 0; // Length of positive and negative results
        int ans = 0;
        
        for (int x : nums) {
            if (x == 0) {
                // Reset both counts when a zero is encountered
                positive = 0;
                negative = 0;
            } else if (x > 0) {
                // Increase positive length, and update negative length
                positive++;
                negative = negative == 0 ? 0 : negative + 1;
            } else {
                // Swap positive and negative lengths and update them
                int temp = positive;
                positive = negative == 0 ? 0 : negative + 1;
                negative = temp + 1;
            }
            // Update the maximum length of positive product subarray
            ans = max(ans, positive);
        }
        
        return ans;
    }
};
