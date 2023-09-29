class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true;  // Indicates if the array is increasing.
        bool isDecreasing = true;  // Indicates if the array is decreasing.

        // Check if the array is either increasing or non-increasing.
        for (int i = 1; i < nums.size(); i++) {
            // Check increasing condition.
            if (nums[i] < nums[i - 1])
                isIncreasing = false;
                
            // Check decreasing condition.
            else if (nums[i] > nums[i - 1])
                isDecreasing = false;

            // If it is neither increasing nor decreasing then don't continue the loop
            if (!isIncreasing && !isDecreasing)
                break;
        }

        return isIncreasing || isDecreasing;  // Return true if either condition is met.
    }
};