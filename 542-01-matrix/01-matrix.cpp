class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first.first, col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            for(int i = 0; i < 4; i++){
                int nrow = row + dx[i], ncol = col + dy[i];
                if (nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && !vis[nrow][ncol])
                {
                    q.push({{nrow, ncol}, steps + 1});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return dist;
    }
};