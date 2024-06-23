class Solution {
    private:
    typedef long long ll;
    vector<vector<ll>> dp;
    ll n;
    ll func(vector<int>&nums,int id,int f){
        if(id>=n) return 0;
        if(dp[id][f]!=-1) return dp[id][f];
         ll take = -1e15,ntake = -1e15;
        if(f==1){
            ntake = (-nums[id])+func(nums,id+1,0);
        }
        take = nums[id]+func(nums,id+1,1);
        return dp[id][f] = max(take,ntake);
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1,vector<ll>(2,-1));
        return nums[0]+func(nums,1,1);
        
    }
};