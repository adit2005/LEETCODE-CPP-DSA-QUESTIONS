class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        
        // If the clicked cell is a mine, change it to 'X' and return
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        // Directions for 8 possible neighbors
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
                                             {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({x, y});
        
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            
            int mines_count = 0; // To count adjacent mines

            // Check all 8 neighbors
            for (auto& dir : directions) {
                int nx = cx + dir.first;
                int ny = cy + dir.second;
                
                // If the cell is within bounds and contains a mine
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
                    mines_count++;
                }
            }
            
            if (mines_count > 0) {
                // If there are adjacent mines, set the current cell to the number of mines
                board[cx][cy] = mines_count + '0';
            } else {
                // If no adjacent mines, set the current cell to 'B' and explore its neighbors
                board[cx][cy] = 'B';
                for (auto& dir : directions) {
                    int nx = cx + dir.first;
                    int ny = cy + dir.second;
                    
                    // If the cell is within bounds and unrevealed ('E')
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'E') {
                        board[nx][ny] = 'B';  // Mark as visited by setting it to 'B'
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return board;
    }
};