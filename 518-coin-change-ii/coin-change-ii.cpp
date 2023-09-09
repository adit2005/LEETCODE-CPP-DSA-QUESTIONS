class Solution {
public:
int change(int amount, vector<int>& coins) {
int n = coins.size();
vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
}
for (int i = 0; i <= amount; i++) {
    dp[0][amount] = 0;
}
dp[0][0] = 1;
for (int coinCount = n - 1; coinCount >= 0; coinCount--) {
    for (int amt = 1; amt <= amount; amt++) {
        if (coins[coinCount] > amt) {
            dp[coinCount][amt] = dp[coinCount + 1][amt];
        } else {
            int pick = dp[coinCount][amt - coins[coinCount]];
            int nonPick = dp[coinCount + 1][amt];
            dp[coinCount][amt] = pick + nonPick;
        }
    }
}
return dp[0][amount];

        
    }
};