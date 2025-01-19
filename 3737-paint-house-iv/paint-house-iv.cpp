class Solution {
public:
    using ll = long long;
    ll n, dp[(ll)1e5 + 5][4][4];

    ll solve(int i, int prev1, int prev2, int n, vector<vector<int>>& cost) {
        if (i >= n / 2) return 0;

        if (dp[i][prev1][prev2] != -1) return dp[i][prev1][prev2];

        ll result = LLONG_MAX;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j != k && j != prev1 && k != prev2) {
                    result = min(result, 
                        cost[i][j] + 
                        cost[n - i - 1][k] + 
                        solve(i + 1, j, k, n, cost));
                }
            }
        }
        return dp[i][prev1][prev2] = result;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        this->n = n;
        for (int i = 0; i <= n / 2; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(0, 3, 3, n, cost);
    }
};