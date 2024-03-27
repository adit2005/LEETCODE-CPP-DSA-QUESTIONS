class Solution {
public:
    int dp[101][101][101];
    int recur(int idx,int a,int b,vector<vector<int>>&costs)
    {
        if(idx>=costs.size())
            return 0;
        int op1=1e9,op2=1e9;
        
        if(dp[idx][a][b]!=-1)
            return dp[idx][a][b];
        if(a)
        {
            op1=costs[idx][0]+recur(idx+1,a-1,b,costs);
            
        }
        if(b)
        {
            op2=costs[idx][1]+recur(idx+1,a,b-1,costs);
        }
        return dp[idx][a][b]=min(op1,op2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        
        int n=costs.size();
        int req=n/2;
        int req1=n/2;
        memset(dp,-1,sizeof dp);
        return recur(0,req,req1,costs);
    }
};