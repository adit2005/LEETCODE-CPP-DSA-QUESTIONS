class Solution {
public:
    int countPartitions(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;

            if(target == 0 || target == nums[0]) return 1;

            return 0 ;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notTaken = countPartitions(ind-1, target, nums, dp);

        int taken = 0 ; 

        if(nums[ind] <= target){
            taken = countPartitions(ind-1, target-nums[ind], nums, dp);
        } 

        return dp[ind][target] = notTaken + taken;


    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tot_sum  = 0;
        for(int i = 0; i<n ; i++){
            tot_sum += nums[i];
        }

        if(tot_sum < target || (tot_sum - target) % 2 != 0){
            return 0;
        }

        int s2= (tot_sum - target) / 2;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return countPartitions(n-1,s2,nums,dp);
    }
};