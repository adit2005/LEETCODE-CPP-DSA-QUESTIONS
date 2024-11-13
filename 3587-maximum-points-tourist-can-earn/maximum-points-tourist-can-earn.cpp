#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        // Initialize dp table, where dp[day][city] represents the maximum score on `day` in `city`
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        
        // Start filling from day k - 1 (second last day) up to day 0
        for (int day = k - 1; day >= 0; --day) {
            for (int city = 0; city < n; ++city) {
                // Option 1: Stay in the same city
                dp[day][city] = stayScore[day][city] + dp[day + 1][city];

                // Option 2: Travel to another city
                for (int nextCity = 0; nextCity < n; ++nextCity) {
                    if (nextCity != city) {
                        dp[day][city] = max(dp[day][city], travelScore[city][nextCity] + dp[day + 1][nextCity]);
                    }
                }
            }
        }
        
        // The answer is the maximum score possible starting from any city on day 0
        int maxPoints = 0;
        for (int startCity = 0; startCity < n; ++startCity) {
            maxPoints = max(maxPoints, dp[0][startCity]);
        }

        return maxPoints;
    }
};
