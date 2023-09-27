class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return calc(1, 1, 1, n, dp);
    }
    int calc(int step, int val, int copy, int n, vector<vector<int>> &dp)
    {
        if (step > n || val > n)
            return INT_MAX;
        if (val == n)
            return step;
        if (dp[step][val] != -1)
            return dp[step][val];
        dp[step][val] = min(calc(step + 1, val + copy, copy, n, dp), calc(step + 2, 2 * val, val, n, dp));
        return dp[step][val];
    }
};