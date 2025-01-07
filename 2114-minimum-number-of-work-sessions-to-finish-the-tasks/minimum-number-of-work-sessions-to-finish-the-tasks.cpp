class Solution {
public:
    int dp[16385][16];
    int f(int mask,vector<int>& tasks, int sessionTime,int curr=0){
        if(mask==((1<<tasks.size()) - 1)){
            return 1;
        }
        if(dp[mask][curr]!=-1){
            return dp[mask][curr];
        }
        int ans=1e9;
        for(int i=0;i<tasks.size();i++)
        {
            if(!((1<<i) & (mask))){
                if(curr+tasks[i]<=sessionTime){
                    ans=min(ans,f((mask | (1<<i)),tasks,sessionTime,curr+tasks[i]));
                }
                else{
                    ans=min(ans,1+f((mask | (1<<i)),tasks,sessionTime,tasks[i]));
                }
            }
        }
        return dp[mask][curr]=ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int mask=0;
        memset(dp,-1,sizeof(dp));
        int ans= f(mask,tasks,sessionTime);
        return ans;
    }
};