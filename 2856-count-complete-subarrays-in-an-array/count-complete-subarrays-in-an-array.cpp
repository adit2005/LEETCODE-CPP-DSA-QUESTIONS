class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;  // This will store the final count of complete subarrays.
        
        unordered_map<int, int> all, mp;  // Maps to count frequency of elements.
        // `all` will store the count of each unique element in the entire array.
        // `mp` will store the count of elements in the current sliding window.

        // Populate the `all` map with the count of each unique element in `nums`.
        for(auto it : nums)
            all[it]++;
        
        int left = 0;  // Left boundary of the sliding window.
        int right = 0; // Right boundary of the sliding window.

        // Start expanding the right boundary of the sliding window.
        while(right < nums.size()) {
            // Include nums[right] in the sliding window.
            mp[nums[right]]++;
            
            // While the current window contains all unique elements.
            while(left <= right && all.size() == mp.size()) {
                // If removing nums[left] still keeps all unique elements in the window.
                if(--mp[nums[left]] == 0)
                    mp.erase(nums[left]);  // Remove nums[left] from the window if its count drops to zero.
                
                
                ans += nums.size() - right;
                
                // Move the left boundary to the right.
                left++;
            }
            
            // Move the right boundary to the right.
            right++;
        }

        return ans;  // Return the total count of complete subarrays.
    }
};
