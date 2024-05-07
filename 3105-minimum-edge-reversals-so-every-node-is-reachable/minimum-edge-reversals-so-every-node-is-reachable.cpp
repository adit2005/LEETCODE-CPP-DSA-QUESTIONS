#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
private:
    unordered_map<int, unordered_map<int, int>> graph; // Store edge weights

    map<pair<int, int>, int> dp;

    int dfs(int node, int parent) {
        if (dp.find({node, parent}) != dp.end())
            return dp[{node, parent}];
        
        int ans = 0;
        for (const auto& neighbor : graph[node]) {
            int neighborNode = neighbor.first;
            int weight = neighbor.second;
            if (neighborNode != parent)
                ans += dfs(neighborNode, node) + weight; // Include the edge weight
        }
        
        dp[{node, parent}] = ans;
        return ans;
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        graph.clear(); // Clear the graph
        
        // Populate the graph with edges and weights
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from][to] = 0; // Store edge weight
            graph[to][from] = 1; // Add the reverse edge with weight 0
        }
        
        vector<int> ans;
        dp.clear(); // Clear the memoization table
        for (int i = 0; i < n; ++i) {
            ans.push_back(dfs(i, -1));
        }
        
        return ans;
    }
};
