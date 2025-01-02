class Solution {
public:
    int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) return 0;
        int res = grid[r][c];
        grid[r][c] = 0;
        for(auto d: dir)  res += dfs(grid, r+d[0], c+d[1]);
        return res;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i< grid.size(); ++i){
            for(int j =0; j < grid[0].size(); ++j){
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};