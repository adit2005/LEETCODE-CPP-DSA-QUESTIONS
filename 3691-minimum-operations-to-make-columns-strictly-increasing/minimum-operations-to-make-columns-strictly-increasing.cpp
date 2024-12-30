class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns
        
        int operations = 0; // To keep track of the total number of operations

        // Traverse each column
        for (int col = 0; col < n; ++col) {
            for (int row = 1; row < m; ++row) {
                // If the current element is not strictly greater than the element above it
                if (grid[row][col] <= grid[row - 1][col]) {
                    // Calculate the difference to make it strictly greater
                    int diff = grid[row - 1][col] - grid[row][col] + 1;
                    operations += diff; // Add the operations needed to the total
                    grid[row][col] += diff; // Update the current element to maintain the condition
                }
            }
        }

        return operations; // Return the total number of operations
    }
};
