class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return static_cast<double>(nums[0]);
        }
        
        int start = 0;
        int end = k;
        double sum = 0.0;
        
        // Calculate the average of the first window
        for (int i = 0; i < k; i++) {
            sum += static_cast<double>(nums[i]);
        }
        
        // Initialize the maximum average
        double max_sum = sum;
        
        // Slide the window and update the maximum average
        while (end < nums.size()) {
            sum = sum - static_cast<double>(nums[start]) ;
            sum = sum + static_cast<double>(nums[end]) ;
            max_sum = max(max_sum, sum);
            start++;
            end++;
        }
        
        return max_sum/k;
    }
};