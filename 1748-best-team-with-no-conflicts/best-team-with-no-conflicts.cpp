class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<pair<int, int>> players(n);
    
    // Step 1: Combine scores and ages, then sort by age, then score
    for (int i = 0; i < n; ++i) {
        players[i] = {ages[i], scores[i]};
    }
    sort(players.begin(), players.end());
    
    // Step 2: Initialize DP array
    vector<int> dp(n, 0);
    int maxScore = 0;

    // Step 3: Fill DP array
    for (int i = 0; i < n; ++i) {
        dp[i] = players[i].second; // Start with player's own score
        for (int j = 0; j < i; ++j) {
            // Check if we can add players[i] to the team ending at players[j]
            if (players[j].second <= players[i].second) {
                dp[i] = max(dp[i], dp[j] + players[i].second);
            }
        }
        maxScore = max(maxScore, dp[i]);
    }
    
    return maxScore;
}
};