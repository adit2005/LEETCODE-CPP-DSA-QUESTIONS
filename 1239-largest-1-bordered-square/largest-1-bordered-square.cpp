class Solution {
public:
    int largest1BorderedSquare(std::vector<std::vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        // Create 2D arrays to store the count of continuous 1's in the down and right directions
        int down[rows][cols];
        int right[rows][cols];
        // Initialize the arrays with zeros
        std::memset(down, 0, sizeof(down));
        std::memset(right, 0, sizeof(right));

        // Fill the down and right arrays with the consecutive 1's count
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    down[i][j] = (i + 1 < rows) ? down[i + 1][j] + 1 : 1;
                    right[i][j] = (j + 1 < cols) ? right[i][j + 1] + 1 : 1;
                }
            }
        }

        // Loop from the maximum possible size of the square to the smallest
        for (int maxSize = std::min(rows, cols); maxSize > 0; --maxSize) {
            // Check each possible position for the top-left corner of the square
            for (int i = 0; i <= rows - maxSize; ++i) {
                for (int j = 0; j <= cols - maxSize; ++j) {
                    // Check if both vertical and horizontal sides have at least 'maxSize' 1's
                    if (down[i][j] >= maxSize && right[i][j] >= maxSize &&
                        right[i + maxSize - 1][j] >= maxSize &&
                        down[i][j + maxSize - 1] >= maxSize) {
                        // If a valid square is found, return its area
                        return maxSize * maxSize;
                    }
                }
            }
        }

        // Return 0 if no 1-bordered square is found
        return 0;
    }
};
