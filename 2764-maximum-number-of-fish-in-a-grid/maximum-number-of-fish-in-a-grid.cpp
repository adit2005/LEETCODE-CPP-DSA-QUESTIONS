class Solution {
private:
    // Helper function to find the root of a component
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]); // Path compression
        }
        return parent[x];
    }

    // Helper function to union two components based on size
    void unionSet(vector<int>& parent, vector<int>& size, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);

        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n), size(m * n, 0);

        // Initialize parent and size arrays
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                if (grid[i][j] > 0) {
                    parent[idx] = idx;
                    size[idx] = grid[i][j];
                }
            }
        }

        // Union adjacent water cells
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int idx1 = i * n + j;
                    for (auto [dx, dy] : directions) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > 0) {
                            int idx2 = ni * n + nj;
                            unionSet(parent, size, idx1, idx2);
                        }
                    }
                }
            }
        }

        // Find the maximum fish count
        int maxFish = 0;
        for (int i = 0; i < m * n; i++) {
            if (parent[i] == i) { // Root node
                maxFish = max(maxFish, size[i]);
            }
        }
        return maxFish;
    }
};
