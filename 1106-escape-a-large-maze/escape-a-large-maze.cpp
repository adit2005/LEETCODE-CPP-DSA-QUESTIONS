#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to check if escape is possible using BFS
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blockedSet;
        for (const auto& p : blocked) {
            blockedSet.insert(hashPoint(p[0], p[1]));
        }
        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }

private:
    // BFS function
    bool bfs(vector<int>& start, vector<int>& end, unordered_set<long long>& blockedSet) {
        queue<pair<int, int>> q;
        unordered_set<long long> visited;
        q.push({start[0], start[1]});
        visited.insert(hashPoint(start[0], start[1]));

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int LIMIT = 20000; // Early stopping condition

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Check all 4 possible directions
            for (const auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                long long hashedPoint = hashPoint(nx, ny);

                // Check bounds, visited set, and blocked set
                if (nx >= 0 && nx < 1'000'000 && ny >= 0 && ny < 1'000'000 &&
                    !visited.count(hashedPoint) && !blockedSet.count(hashedPoint)) {
                    if (nx == end[0] && ny == end[1]) {
                        return true; // Target reached
                    }
                    q.push({nx, ny});
                    visited.insert(hashedPoint);
                }
            }

            // If visited size exceeds LIMIT, return true (early escape detection)
            if (visited.size() >= LIMIT) {
                return true;
            }
        }

        return false;
    }

    // Function to hash a 2D point into a single integer for use in sets
    long long hashPoint(int x, int y) {
        return (static_cast<long long>(x) << 32) | y;
    }
};
