class Solution {
public:
    // Function to compute the 2D prefix sum array of a given grid
    vector<vector<int>> pref2d(vector<vector<int>>& v, int m, int n) {
        // Create a prefix sum array of size (m+1) x (n+1) initialized to 0
        vector<vector<int>> p(m + 1, vector<int>(n + 1));
        // Compute prefix sums for every cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Prefix sum formula: current cell + left prefix + top prefix - overlap
                p[i + 1][j + 1] = v[i][j] + p[i + 1][j] + p[i][j + 1] - p[i][j];
            }
        }
        return p;
    }

    // Function to compute the sum of elements in a subrectangle using the 2D prefix sum array
    int sum2d(vector<vector<int>>& p, int c1, int r1, int c2, int r2) {
        // Calculate the sum of the rectangle defined by corners (c1, r1) and (c2, r2)
        return p[c2 + 1][r2 + 1] + p[c1][r1] - p[c1][r2 + 1] - p[c2 + 1][r1];
    }

    // Main function to determine if it's possible to stamp the grid
    bool possibleToStamp(vector<vector<int>>& g, int h, int w) {
        int m = g.size(), n = g[0].size(); // Dimensions of the grid

        // Step 1: Create a grid to mark the bottom-right corner of valid stamps
        vector<vector<int>> stamp(m, vector<int>(n));

        // Compute the prefix sum array for the grid
        auto pref = pref2d(g, m, n);

        // Iterate over the grid to check where a stamp of size h x w can fit
        for (int i = h - 1; i < m; ++i) {
            for (int j = w - 1; j < n; ++j) {
                // Use the prefix sum to check if the area of the rectangle (h x w) is all zeros
                if (sum2d(pref, i - h + 1, j - w + 1, i, j) == 0) {
                    stamp[i][j] = 1; // Mark the bottom-right corner as valid for a stamp
                }
            }
        }

        // Step 2: Create a prefix sum array for the stamp grid to enable fast range queries
        auto pref2 = pref2d(stamp, m, n);

        // Step 3: Verify if all zeros in the grid are covered by a stamp
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the current cell is zero in the grid
                if (g[i][j] == 0) {
                    // Check if there is at least one stamp that covers this cell
                    if (sum2d(pref2, i, j, min(m - 1, i + h - 1), min(n - 1, j + w - 1)) == 0) {
                        // If no stamp covers this cell, return false
                        return false;
                    }
                }
            }
        }

        // If all zeros are covered, return true
        return true;
    }
};

