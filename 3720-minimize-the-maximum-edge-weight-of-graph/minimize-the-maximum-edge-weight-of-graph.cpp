class Solution {
public:
    // DFS function to count reachable nodes with max weight constraint
    int dfs(int node, int maxWeight, vector<vector<pair<int, int>>>& ral, vector<int>& visited) {
        int reachableCount = 1; // Start with the current node
        visited[node] = 1;      // Mark the current node as visited
        
        for (auto [neighbor, weight] : ral[node]) {
            if (weight <= maxWeight && !visited[neighbor]) {
                reachableCount += dfs(neighbor, maxWeight, ral, visited);
            }
        }
        return reachableCount;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // Step 1: Build the reversed adjacency list (RAL)
        vector<vector<pair<int, int>>> ral(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            ral[v].emplace_back(u, w);
        }

        // Step 2: Binary search for the minimum maximum edge weight
        int left = 1, right = 1e6 + 1; // Define binary search range
        while (left < right) {
            int mid = (left + right) / 2; // Midpoint of the current range
            
            // Check if all nodes can be reached with the current max weight
            vector<int> visited(n, 0);
            if (dfs(0, mid, ral, visited) == n) {
                right = mid; // Try to minimize further
            } else {
                left = mid + 1; // Increase the max weight
            }
        }

        // If left is beyond the valid range, return -1 (impossible case)
        return left == 1e6 + 1 ? -1 : left;
    }
};
