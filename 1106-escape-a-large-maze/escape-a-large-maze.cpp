#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to check if escape is possible
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        // Sets for visited cells and blocked cells, using hashed values
        unordered_set<long long> visited;
        unordered_set<long long> blockedSet;

        // Insert all blocked cells into the set
        for (const auto& cell : blocked) {
            blockedSet.insert(hashPoint(cell[0], cell[1]));
        }

        // Perform DFS from source to target and target to source
        bool fromSource = dfs(visited, blockedSet, source[0], source[1], target[0], target[1]);
        visited.clear(); // Clear visited set for the second DFS
        bool fromTarget = dfs(visited, blockedSet, target[0], target[1], source[0], source[1]);

        return fromSource && fromTarget;
    }

private:
    // Function to hash a 2D point into a single integer
    long long hashPoint(int x, int y) {
        return (static_cast<long long>(x) << 32) | y;
    }

    // DFS function to traverse the grid
    bool dfs(unordered_set<long long>& visited, unordered_set<long long>& blockedSet,
             int x, int y, int targetX, int targetY) {
        // Directions: right, left, up, down
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        // Mark the current cell as visited
        visited.insert(hashPoint(x, y));

        // Early stopping condition: if visited size exceeds 20000
        if (visited.size() >= 20000) {
            return true;
        }

        // If the target cell is reached
        if (x == targetX && y == targetY) {
            return true;
        }

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            long long hashedNewPoint = hashPoint(newX, newY);

            // Check bounds, if the cell is visited or blocked
            if (newX >= 0 && newY >= 0 && newX < 1'000'000 && newY < 1'000'000 &&
                visited.find(hashedNewPoint) == visited.end() &&
                blockedSet.find(hashedNewPoint) == blockedSet.end()) {
                
                // Recur for the next cell
                if (dfs(visited, blockedSet, newX, newY, targetX, targetY)) {
                    return true;
                }
            }
        }

        return false;
    }
};
