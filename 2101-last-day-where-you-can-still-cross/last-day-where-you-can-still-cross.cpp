#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    bool isPossible(int m, int n, int t, vector<vector<int>>& cells) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // Grid representation
        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Possible directions

        for (int i = 0; i <= t; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1; // Mark cells from the given list as blocked
        }

        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 0) {
                q.push({0, i}); // Start BFS from the top row
                grid[0][i] = 1; // Mark the cell as visited
            }
        }
        
        while (!q.empty()) {
            int l = q.size();
            while(l--){
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first, c = p.second; // Current cell coordinates
            
            if (r == m - 1) {
                return true; // Found a path to the bottom row
            }
            
            for (auto d : directions) {
                int nr = r + d.first, nc = c + d.second; // Neighbor cell coordinates
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // Mark the neighbor cell as visited
                    q.push({nr, nc}); // Add the neighbor cell to the queue for further exploration
                }
            }
        }
        }
        return false; // Unable to find a path to the bottom row
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = row * col, latestPossibleDay = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the mid-day
            if (isPossible(row, col, mid, cells)) {
                left = mid + 1; // Update the left pointer to search in the upper half
                latestPossibleDay = mid+1; // Update the latest possible day
            } else {
                right = mid - 1; // Update the right pointer to search in the lower half
            }
        }
        return latestPossibleDay;
    }
};
