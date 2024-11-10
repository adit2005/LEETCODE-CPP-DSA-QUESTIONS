class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Initialize variables for Kadane's algorithm
        int max_sum = 0, min_sum = 0;
        int current_max = 0, current_min = 0;
        
        // Traverse through the array to find max subarray sum and min subarray sum
        for (int num : nums) {
            // Kadane for max sum
            current_max = max(num, current_max + num);
            max_sum = max(max_sum, current_max);
            
            // Kadane for min sum
            current_min = min(num, current_min + num);
            min_sum = min(min_sum, current_min);
        }
        
        // The maximum absolute sum is the max of |max_sum| and |min_sum|
        return max(abs(max_sum), abs(min_sum));
    }
};
