class Solution {
public:
        vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> G, dp;
        for (auto& e : edges) {
          G[e[0]][e[1]] = 0, G[e[1]][e[0]] = 1;
          dp[e[0]][e[1]] = dp[e[1]][e[0]] = dp[-1][e[0]] = dp[-1][e[1]] = -1;
        }

        function<int(int, int)> dfs = [&](int i, int j) {
          if (dp[i][j] >= 0)
              return dp[i][j];
          dp[i][j] = 0;
          for (const auto& k : G[j]) {
            if (k.first == i) continue;
            dp[i][j] += dfs(j, k.first) + k.second;
          }
          return dp[i][j];
        };

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
          res[i] = dfs(-1, i);
        }
        return res;
    }
};