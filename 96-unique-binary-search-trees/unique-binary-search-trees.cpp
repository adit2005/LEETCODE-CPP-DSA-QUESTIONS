class Solution {
public:


int func(int n , vector<int>&dp){
    if(n<=1) return 1;
    if(dp[n] != -1) return dp[n]; //because this is already visited 
    int count =0;

    for(int i =1 ;i<=n;i++){
        count += func(i-1,dp)* func(n-i ,dp);
    }

      return dp[n] = count;
}
    int numTrees(int n) {
     vector<int>dp(n+1, -1);
     return func(n ,dp);

      
    }
};