class Solution {
public:
   // Directions for north, east, south, west
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<char>> grid(m, vector<char>(n, 'U')); // U for unguarded

    // Mark guards and walls on the grid
    for (auto& g : guards) {
        grid[g[0]][g[1]] = 'G'; // G for guard
    }
    for (auto& w : walls) {
        grid[w[0]][w[1]] = 'W'; // W for wall
    }

    // Perform simulation from each guard
    for (auto& g : guards) {
        int x = g[0], y = g[1];
        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;

            // Start traversing only if the next cell is not a wall
            while (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 'W' && grid[nx][ny] != 'G') {
                grid[nx][ny] = 'V'; // Mark cell as guarded
                nx += dir.first;
                ny += dir.second;
            }
        }
    }

    // Count unguarded cells
    int unguardedCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'U') unguardedCount++;
        }
    }

    return unguardedCount;
}
};