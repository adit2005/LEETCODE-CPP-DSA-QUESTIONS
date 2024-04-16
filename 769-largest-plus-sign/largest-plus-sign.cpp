class Solution {
public:
    void computeOrderOfPlus(vector<vector<int>>& grid, vector<vector<int>>& dp, int n){
        
        int leftToRight = 0, topToBottom = 0, rightToBottom = 0, bottomToTop = 0;
        
        for(int i=0; i<n; ++i){
            leftToRight = 0, topToBottom = 0; // reset value becuase we restarting counting for each row
            for(int j=0; j<n; ++j){
                // calcualte continuous 1s present left to current cell until zero
                leftToRight = grid[i][j] ? leftToRight+1 : 0;
                dp[i][j] = min(dp[i][j], leftToRight);
                
                // calcualte continuous 1s present top till current cell until zero
                topToBottom = grid[j][i] ? topToBottom+1 : 0; // here cell ( j, i ) because we compute top to bottom.
                dp[j][i] = min(dp[j][i], topToBottom);
            }
        }
        
        for(int i=0; i<n; ++i){
            rightToBottom = 0, bottomToTop = 0;
            for(int j=n-1; j>=0; --j){
                // calcualte continuous 1s present right to current cell
                rightToBottom = grid[i][j] ? rightToBottom+1 : 0;
                dp[i][j] = min(dp[i][j], rightToBottom);
                
                // calcualte continuous 1s present bottom till current cell
                bottomToTop = grid[j][i] ? bottomToTop+1 : 0; // here cell ( j, i ) because we compute bottom to top
                dp[j][i] = min(dp[j][i], bottomToTop); 
            }
        }
    }
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));//prefill with 1s
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));// initialize with max value so later will update with minimum left, right, top, bottom distance
        
        for(auto mine: mines){
            grid[mine.at(0)][mine.at(1)] = 0; // fill grid with zero
        }
        
        computeOrderOfPlus(grid, dp, n);
        // fillDP(dp, grid, n);
        
        int res = 0;
        // get the maximum value from dp matrix
        for(auto row: dp){
            for(auto ele : row){
                res = max(res, ele);
            }
        }
        
        return res;
    }
};