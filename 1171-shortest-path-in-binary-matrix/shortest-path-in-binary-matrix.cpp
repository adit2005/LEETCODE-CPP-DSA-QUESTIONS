class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size(); // Get the size of the grid (assuming it's a square grid).
        
        // Check if the starting or ending cell is blocked (1). If so, there's no path.
        if (g[0][0] || g[n-1][n-1])
            return -1;
        
        g[0][0] = 1; // Mark the starting cell as visited.
        queue<pair<int, int>> q; // Create a queue to perform BFS.
        q.push({0, 0}); // Push the starting cell into the queue.
        int t = 0; // Initialize a variable to count the number of steps taken.

        // Start BFS
        while (!q.empty()) {
            int k = q.size(); // Get the number of cells at the current level (BFS level).
            t++; // Increment the step counter.

            // Process all cells at the current level.
            while (k--) {
                int x = q.front().first; // Get the x-coordinate of the cell.
                int y = q.front().second; // Get the y-coordinate of the cell.
                q.pop(); // Remove the cell from the queue.

                // If we have reached the bottom-right corner, return the number of steps taken.
                if (x == n - 1 && y == n - 1)
                    return t;

                // Define eight possible directions to move (up, down, left, right, and diagonals).
                int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
                int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

                // Check each of the eight possible neighbors.
                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i]; // Calculate the x-coordinate of the neighbor.
                    int ny = y + dy[i]; // Calculate the y-coordinate of the neighbor.

                    // Check if the neighbor is within bounds and is an open cell (0).
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && g[nx][ny] == 0) {
                        g[nx][ny] = 1; // Mark the neighbor as visited.
                        q.push({nx, ny}); // Add the neighbor to the queue for further exploration.
                    }
                }
            }
        }

        // If we reach this point, there is no valid path to the destination.
        return -1;
    }
};
