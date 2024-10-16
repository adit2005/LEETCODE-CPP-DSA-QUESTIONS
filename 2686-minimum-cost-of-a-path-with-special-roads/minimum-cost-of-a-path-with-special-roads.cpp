#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n = specialRoads.size();
        vector<int> dist(n, INT_MAX); // Store the minimum distance to reach each special road.
        
        // Min-heap to store distances with the corresponding index of special road.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Initialize distances from start to each special road.
        for (int i = 0; i < n; ++i) {
            int x1 = specialRoads[i][0], y1 = specialRoads[i][1];
            int x2 = specialRoads[i][2], y2 = specialRoads[i][3];
            int cost = specialRoads[i][4];
            
            // Calculate distance from start to the start of the special road plus the special road cost.
            int startToSpecialRoad = abs(start[0] - x1) + abs(start[1] - y1) + cost;
            dist[i] = startToSpecialRoad;
            pq.push({startToSpecialRoad, i});
        }
        
        int minCost = abs(start[0] - target[0]) + abs(start[1] - target[1]); // Direct path without using special roads.

        // Dijkstra's algorithm to process each special road.
        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();
            
            // If the distance in the priority queue is outdated, skip it.
            if (currentDist > dist[u]) continue;
            
            int x2 = specialRoads[u][2], y2 = specialRoads[u][3];
            
            // Calculate cost from this special road to the target point.
            minCost = min(minCost, currentDist + abs(x2 - target[0]) + abs(y2 - target[1]));
            
            // Relax the edges (special roads) connected to the current special road.
            for (int v = 0; v < n; ++v) {
                if (u == v) continue; // Skip the same special road.

                int x1 = specialRoads[v][0], y1 = specialRoads[v][1];
                int nextDist = currentDist + abs(x2 - x1) + abs(y2 - y1) + specialRoads[v][4];

                // If the new distance is better, update and push it to the priority queue.
                if (nextDist < dist[v]) {
                    dist[v] = nextDist;
                    pq.push({nextDist, v});
                }
            }
        }

        return minCost;
    }
};
