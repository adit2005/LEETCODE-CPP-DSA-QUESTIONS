class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list for all nodes
        vector<vector<int>> neighbors(n);
        for (auto edge: edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        // Vector to track visited nodes
        vector<bool> visited(n);

        // Variables to keep track of the sum of sizes of all components and sum of squares of component sizes
        long long sum = 0, squaresum = 0;

        // Step 2: Iterate over all nodes to find connected components
        for (int i = 0; i < n; i++) {
            // If the node is not visited, perform a DFS to find the size of the connected component
            if (!visited[i]) {
                long long ans = (long long) dfs(i, neighbors, visited);
                squaresum += ans * ans; // Add the square of the component size
                sum += ans;             // Add the component size to the total sum
            }
        }

        // Step 3: Calculate the total number of unreachable pairs using the formula
        // (sum * sum - squaresum) / 2 gives the count of pairs that are not connected directly.
        return (sum * sum - squaresum) / 2;
    }

private:
    // DFS function to find the size of the connected component starting from node `n`
    int dfs(int n, vector<vector<int>>& neighbors, vector<bool>& visited) {
        visited[n] = true;
        int ans = 1; // Initialize the component size as 1 (current node)
        for (auto neighbor: neighbors[n]) {
            // Recursively visit all unvisited neighbors and add their sizes
            if (!visited[neighbor]) {
                ans += dfs(neighbor, neighbors, visited);
            }
        }
        return ans;
    }
};
