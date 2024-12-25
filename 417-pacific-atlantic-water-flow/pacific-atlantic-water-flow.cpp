#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixHeights;
    int rows;
    int cols;

    // This method will be used to find all cells that can reach both the Pacific and Atlantic oceans.
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        this->matrixHeights = heights;
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;
        unordered_set<int> pacificVisited;
        unordered_set<int> atlanticVisited;

        // Initialize the queues with cells adjacent to the Pacific and Atlantic oceans.
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || j == 0) {
                    pacificVisited.insert(i * cols + j);
                    pacificQueue.emplace(i, j);
                }
                if (i == rows - 1 || j == cols - 1) {
                    atlanticVisited.insert(i * cols + j);
                    atlanticQueue.emplace(i, j);
                }
            }
        }
      
        // Perform BFS for both the Pacific and Atlantic oceans.
        bfs(pacificQueue, pacificVisited);
        bfs(atlanticQueue, atlanticVisited);

        // Collect cells that can reach both oceans.
        vector<vector<int>> answer;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int cellIndex = i * cols + j;
                if (pacificVisited.count(cellIndex) && atlanticVisited.count(cellIndex)) {
                    answer.push_back({i, j});
                }
            }
        }
        return answer;
    }

    // This method performs Breadth-First Search (BFS) starting from the cells adjacent to a given ocean.
    void bfs(queue<pair<int, int>>& q, unordered_set<int>& visited) {
        vector<int> directions = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = cell.first + directions[i];
                int y = cell.second + directions[i + 1];
                // Check for the valid cell and that the new cell's height is not less than the current cell's height
                if (x >= 0 && x < rows && y >= 0 && y < cols && !visited.count(x * cols + y) && matrixHeights[x][y] >= matrixHeights[cell.first][cell.second]) {
                    visited.insert(x * cols + y);
                    q.emplace(x, y);
                }
            }
        }
    }
};