#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to implement Dijkstra's algorithm
    vector<long long> dijkstra(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n + 1);

        // Build the graph
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w); // Undirected graph
        }

        // Min-heap for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n + 1, LLONG_MAX);
        
        // Start from node n
        dist[n] = 0;
        pq.emplace(0, n);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            
            // If the distance is not up to date
            if (d > dist[u]) continue;

            // Explore neighbors
            for (const auto& [v, weight] : graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }
        
        return dist;
    }

    // DFS function to count restricted paths
    long long dfs(int node, int n, vector<long long>& dist, vector<vector<pair<int, int>>>& graph, unordered_map<int, long long>& memo) {
        if (node == n) return 1; // Reached destination
        
        if (memo.count(node)) return memo[node]; // Return memoized result

        long long count = 0;
        
        // Explore neighbors
        for (const auto& [neighbor, weight] : graph[node]) {
            // Only consider this path if the distance condition is met
            if (dist[node] > dist[neighbor]) {
                count = (count + dfs(neighbor, n, dist, graph, memo)) % MOD;
            }
        }
        
        return memo[node] = count; // Store the result in the memoization map
    }

    // Main function to find the number of restricted paths
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        // Step 1: Get distances from node n
        vector<long long> dist = dijkstra(n, edges);

        // Step 2: Build the graph again for DFS
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        unordered_map<int, long long> memo;
        // Step 3: Count restricted paths using DFS
        return dfs(1, n, dist, graph, memo);
    }
};
