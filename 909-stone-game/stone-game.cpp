class Solution {
public:
   bool solve(vector<int>& piles, int start, int end, bool turn,vector<vector<int>> &dp)
    {
        if(start>end)
        return 0;

        if(dp[start][end]!=-1)
        return dp[start][end];


        if(turn)
        {
            int rr1 = solve(piles,start+1,end,false,dp) + piles[start];
            int rr2 = solve(piles,start,end-1,false,dp) + piles[end];
            return dp[start][end] = max(rr1,rr2);
        }
        int rr1 = solve(piles,start+1,end,true,dp) - piles[start];
        int rr2 = solve(piles,start,end-1,true,dp) - piles[end];
        return dp[start][end] = max(rr1,rr2);
    }
    bool stoneGame(vector<int>& piles) {
        int start = 0, end = piles.size()-1;
        bool turn = true;
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(piles,start,end,turn,dp);
    }
};