class Solution {
public:
    int countSubarrays(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0; // If fewer than 3 elements, no valid subarrays.
    
    int count = 0; // Counter for valid subarrays.

    // Sliding window approach.
    for (int i = 0; i <= n - 3; ++i) {
        int first = nums[i];
        int middle = nums[i + 1];
        int third = nums[i + 2];
        
        // Check if the condition is satisfied.
        if ((first + third)*2 == middle ) {
            count++;
        }
    }
    
    return count;
}

};