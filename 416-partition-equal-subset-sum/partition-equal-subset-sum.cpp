class Solution {
public:
    bool subsetSumUtil(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
      
   
    if (target == 0)
        return true;

    
    if (ind == 0)
        return nums[0] == target;

    
    if (dp[ind][target] != -1)
        return dp[ind][target];

   
   
    bool notTaken = subsetSumUtil(ind - 1, target, nums, dp);

   
    bool taken = false;
    if (nums[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - nums[ind], nums, dp);

    
    return dp[ind][target] = notTaken || taken;
}
    
    
    bool canPartition(vector<int>& nums) {
        int totSum = 0;

        int n = nums.size();

   
    for (int i = 0; i < n; i++) {
        totSum += nums[i];
    }

   
    if (totSum % 2 == 1)
        return false;
    else {
        int k = totSum / 2;

        
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        
        return subsetSumUtil(n - 1, k, nums, dp);
    }
    }
};