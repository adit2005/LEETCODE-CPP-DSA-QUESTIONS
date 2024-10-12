class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // Initialize 'ans' to the smallest possible value.
        long long ans = LLONG_MIN;
        
        // Create a prefix sum array to store cumulative sums.
        vector<long long> pre(nums.size() + 1);
        pre[0] = 0; // Initialize the first element as 0 for easier calculations.
        
        // Fill the prefix sum array.
        for(int i = 1; i <= nums.size(); i++){
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        
        // Create a hash map to store the last seen index of each number.
        unordered_map<int, int> mp;
        
        // Iterate through the array to find the maximum sum subarray.
        for(int i = 0; i < nums.size(); i++){
            int curEle = nums[i]; // Current element.
            
            // Check if 'curEle - k' exists in the map, which means there is a subarray ending at 'i' with the required difference.
            if(mp.find(curEle - k) != mp.end()){
                // Calculate the sum of the subarray and update 'ans' with the maximum value.
                ans = max(ans, pre[i + 1] - pre[mp[curEle - k]]);
            }
            
            // Check if 'curEle + k' exists in the map.
            if(mp.find(curEle + k) != mp.end()){
                // Calculate the sum of the subarray and update 'ans' with the maximum value.
                ans = max(ans, pre[i + 1] - pre[mp[curEle + k]]);
            }
            
            // Update the map with the current element's index.
            if(mp.find(curEle) != mp.end()){
                // If 'curEle' exists in the map, check if the subarray sum from its last occurrence to 'i' is non-positive.
                if(pre[i]  <  pre[mp[curEle]] )
                    mp[curEle] = i; // Update the index if starting fresh might be beneficial.
            }
            else {
                // If 'curEle' is not in the map, add it with its current index.
                mp[curEle] = i;
            }
        }
        
        // If 'ans' is still LLONG_MIN, return 0 (no valid subarray found).
        if(ans == LLONG_MIN) return 0;
        
        // Otherwise, return the maximum sum found.
        return ans;
    }
};
