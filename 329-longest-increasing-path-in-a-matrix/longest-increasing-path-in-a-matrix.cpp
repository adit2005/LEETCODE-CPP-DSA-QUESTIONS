class Solution {
public:

    int x = 0;
    int y = 0;
    bool isValid(int i, int j){
        if(i>=0 && i<x && j>=0 && j<y){
            return true;
        }
        return false;
    }

    // this dfs function should return the largest increasing path, starting at that i,j.
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j]){
            return dp[i][j];
        }
        int tans = 0;
        if(isValid(i+1, j) && (matrix[i+1][j] > matrix[i][j])){
            tans = max(tans,dfs(i+1,j,matrix,dp));
        }
        if(isValid(i-1, j) && (matrix[i-1][j] > matrix[i][j])){
            tans = max(tans, dfs(i-1,j,matrix,dp));
        }
        if(isValid(i, j+1) && (matrix[i][j+1] > matrix[i][j])){
            tans = max(tans,dfs(i,j+1,matrix,dp));
        }
        if(isValid(i, j-1) && (matrix[i][j-1] > matrix[i][j])){
            tans = max(tans,dfs(i,j-1,matrix,dp));
        }
        dp[i][j] = tans+1;
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // you can store the longest increasing path in dp for some positions and when you reach that position another time
        // instead of calculating it you can just return the longest from there.
        // so maybe recursion + memoization
        // dfs/bfs + recursion + memoization.
        x = matrix.size();
        y = matrix[0].size();
        vector<vector<int>> dp(x, vector<int>(y,0));
        int ans = 0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(dp[i][j]==0){
                    dp[i][j] = dfs(i,j,matrix,dp);
                }
                
                ans = max(ans,dp[i][j]);
            }
          
        }
        return ans;
    }
};