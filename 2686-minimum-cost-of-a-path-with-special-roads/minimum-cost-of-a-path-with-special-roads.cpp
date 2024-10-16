

typedef long long ll;
class Solution {
public:
    // Helper function that calculates the minimum cost using recursion and memoization.
    // `index` represents the current special road being considered.
    // `pre` stores the index of the last special road used (or -1 if none have been used).
    // `x1`, `y1` are the coordinates of the starting point.
    // `x2`, `y2` are the coordinates of the target point.
    // `specialRoads` is the list of special roads with format {x1, y1, x2, y2, cost}.
    // `dp` is the memoization table.
    ll solve(ll index, ll pre, int x1, int y1, int x2, int y2, vector<vector<int>>& specialRoads, vector<vector<int>>& dp) {
        // Base case: if all special roads have been considered.
        if (index == specialRoads.size()) {
            ll x = 0;
            // If no previous special road was used, calculate Manhattan distance from start to target.
            if (pre == -1) {
                x = abs(x2 - x1) + abs(y2 - y1);
            } else {
                // Otherwise, calculate distance from the end of the last used special road to the target.
                x = abs(x2 - specialRoads[pre][2]) + abs(y2 - specialRoads[pre][3]);
            }
            return x;
        }

        // If the solution is already computed, return it.
        if (dp[index + 1][pre + 1] != -1) {
            return dp[index + 1][pre + 1];
        }

        // Initialize variables for the minimum costs of picking or not picking the current special road.
        ll pick = 1e9, notPick = 1e9;

        // Option 1: Do not use the current special road, move to the next one.
        notPick = min(notPick, solve(index + 1, pre, x1, y1, x2, y2, specialRoads, dp));

        // Determine the previous coordinates, either start point or the end of the last used special road.
        ll pre1 = -1, pre2 = -1;
        if (pre == -1) {
            pre1 = x1;
            pre2 = y1;
        } else {
            pre1 = specialRoads[pre][2];
            pre2 = specialRoads[pre][3];
        }

        // Calculate the cost to use the current special road.
        // `t` is the distance to reach the start of this special road from the previous position.
        ll t = abs(specialRoads[index][0] - pre1) + abs(specialRoads[index][1] - pre2);

        // Add the cost of using this special road and solve recursively.
        pick = min(pick, specialRoads[index][4] + t + solve(index + 1, index, x1, y1, x2, y2, specialRoads, dp));

        // Store the minimum of picking or not picking the current road in the memoization table.
        return dp[index + 1][pre + 1] = min(pick, notPick);
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        ll index = 0, pre = -1;

        // Initialize a memoization table with size 402x402 and fill it with -1.
        // The extra space is to handle zero-based indexing and accommodate `index` and `pre` values.
        vector<vector<int>> dp(402, vector<int>(402, -1));

        // Create a new list `v` that duplicates the `specialRoads` list.
        // This is done to have a consistent data structure while solving.
        vector<vector<int>> v = specialRoads;
        for (int i = 0; i < specialRoads.size(); i++) {
            v.push_back(specialRoads[i]);
        }

        // Call the helper function to calculate the minimum cost.
        // It starts with index 0 and no previous special road used (`pre = -1`).
        return solve(index, pre, start[0], start[1], target[0], target[1], v, dp);
    }
};
