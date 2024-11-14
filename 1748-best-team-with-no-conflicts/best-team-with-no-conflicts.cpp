#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int memo[1001][1001]; // Adjust size as per constraints

    int dfs(int i, int prev_index, const vector<pair<int, int>>& players) {
        if (i >= players.size()) return 0;
        
        // Memoization check
        if (memo[i][prev_index + 1] != -1) return memo[i][prev_index + 1];
        
        // Option 1: Skip the current player
        int skip = dfs(i + 1, prev_index, players);
        
        // Option 2: Pick the current player (only if there's no conflict)
        int pick = 0;
        if (prev_index == -1 || players[i].second >= players[prev_index].second) {
            pick = players[i].second + dfs(i + 1, i, players);
        }

        // Store and return the maximum of both choices
        return memo[i][prev_index + 1] = max(skip, pick);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players;
        
        // Pair ages and scores together and sort them
        for (int i = 0; i < n; ++i) {
            players.emplace_back(ages[i], scores[i]);
        }
        sort(players.begin(), players.end()); // Sort by age, then by score
        
        // Initialize memo array
        memset(memo, -1, sizeof(memo));
        
        // Start DFS from the first player with no previous player chosen
        return dfs(0, -1, players);
    }
};
