class Solution {
public:
    int n, m; // Dimensions of the grid
    int dx[4] = {1, 0, -1, 0}; // Array to represent movement in x-direction (down, right, up, left)
    int dy[4] = {0, 1, 0, -1}; // Array to represent movement in y-direction (down, right, up, left)

    // Function to check if a given (x, y) coordinate is inside the grid
    bool inside(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    // Function to check if the person can walk from (srcX, srcY) to (destX, destY)
    // without moving the box
    bool canWalk(int srcX, int srcY, int destX, int destY, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        // If the person has already reached the destination
        if (srcX == destX && srcY == destY) return true;

        visited[srcX][srcY] = 1; // Mark the current position as visited

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            int x = srcX + dx[i]; // New x-coordinate
            int y = srcY + dy[i]; // New y-coordinate

            // Check if the new position is inside the grid, not an obstacle, and not yet visited
            if (inside(x, y) && grid[x][y] != '#' && !visited[x][y]) {
                if (canWalk(x, y, destX, destY, grid, visited)) // Recursively check if we can reach the destination
                    return true;
            }
        }
        return false; // If no valid path is found
    }

    // Main function to find the minimum number of pushes to move the box to the target position
    int minPushBox(vector<vector<char>>& grid) {
        n = grid.size(); // Number of rows
        m = grid[0].size(); // Number of columns

        // Variables to store the positions of the box, target, and person
        int boxX, boxY, targetX, targetY, personX, personY; 

        // Find the initial positions of the box (B), target (T), and person (S)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S') {
                    personX = i; // Person's starting X-coordinate
                    personY = j; // Person's starting Y-coordinate
                } else if (grid[i][j] == 'T') {
                    targetX = i; // Target X-coordinate
                    targetY = j; // Target Y-coordinate
                } else if (grid[i][j] == 'B') {
                    boxX = i; // Box's starting X-coordinate
                    boxY = j; // Box's starting Y-coordinate
                }
            }
        }

        queue<vector<int>> q; // Queue to store the states for BFS
        set<vector<int>> seen; // Set to store visited states to avoid processing them again
        q.push({boxX, boxY, personX, personY}); // Initialize the queue with the starting positions
        int ans = 0; // Variable to store the number of pushes

        // Perform BFS
        while (!q.empty()) {
            int sz = q.size(); // Number of states to process at this level
            while (sz--) {
                auto p = q.front(); // Get the current state
                q.pop();
                boxX = p[0]; // Current X-coordinate of the box
                boxY = p[1]; // Current Y-coordinate of the box
                personX = p[2]; // Current X-coordinate of the person
                personY = p[3]; // Current Y-coordinate of the person

                // If the box has reached the target, return the number of pushes
                if (boxX == targetX && boxY == targetY)
                    return ans;

                grid[boxX][boxY] = '#'; // Temporarily mark the box's position as an obstacle

                // Try to push the box in all four directions
                for (int i = 0; i < 4; i++) {
                    int new_boxX = boxX + dx[i]; // New X-coordinate for the box after the push
                    int new_boxY = boxY + dy[i]; // New Y-coordinate for the box after the push
                    int new_personX = boxX - dx[i]; // Person's position required to push the box
                    int new_personY = boxY - dy[i]; // Person's position required to push the box

                    vector<int> curPos({new_boxX, new_boxY, new_personX, new_personY}); // New state
                    vector<vector<int>> visited(n, vector<int>(m, 0)); // Visited array for the `canWalk` function

                    // Check if the new box position is inside the grid, not an obstacle,
                    // and if the person can reach the required position to push the box
                    if (inside(new_boxX, new_boxY) && grid[new_boxX][new_boxY] != '#' &&
                        !seen.count(curPos) && canWalk(personX, personY, new_personX, new_personY, grid, visited)) {
                        
                        seen.insert(curPos); // Mark the new state as visited
                        q.push(curPos); // Add the new state to the queue
                    }
                }
                grid[boxX][boxY] = '.'; // Restore the box's position
            }
            ans++; // Increment the number of pushes after processing all states at this level
        }
        return -1; // If no solution is found, return -1
    }
};
