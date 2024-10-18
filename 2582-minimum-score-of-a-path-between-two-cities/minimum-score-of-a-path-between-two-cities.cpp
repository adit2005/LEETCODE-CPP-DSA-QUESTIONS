class Solution {
public:
    // Data structures to store visited nodes and adjacency list
    unordered_set<int> s; // Set to keep track of visited nodes.
    unordered_map<int, vector<int>> mp; // Adjacency list representation of the graph.

    int minScore(int n, vector<vector<int>>& roads) {
        // Step 1: Build adjacency list for the graph using the roads information.
        for(auto& r : roads) {
            mp[r[0]].push_back(r[1]);
            mp[r[1]].push_back(r[0]);
        }

        // Step 2: Use DFS to find all nodes connected to node 1.
        dfs(1);
        // At this point, set `s` contains all nodes that are reachable from node 1.

        // Step 3: Find the minimum edge weight among roads that involve nodes in set `s`.
        int ans = INT_MAX; // Initialize with a large value.
        for(auto& r : roads) {
            // If one of the nodes of the road is in set `s`, consider its weight.
            if(s.find(r[0]) != s.end()) {
                ans = min(ans, r[2]); // Update `ans` with the minimum weight.
            }
        }
        return ans; // Return the minimum edge weight found.
    }

    // Helper function: Depth-First Search (DFS) to explore connected nodes.
    void dfs(int root) {
        // If the node is already visited, return.
        if(s.find(root) != s.end()) return;

        // Mark the node as visited by adding it to the set.
        s.insert(root);

        // Recursively visit all connected nodes.
        for(auto& child : mp[root]) {
            dfs(child);
        }
    }
};
