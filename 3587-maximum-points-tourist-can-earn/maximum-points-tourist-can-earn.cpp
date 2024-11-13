#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        // Memoization table to store results for each (city, day) state
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        
        // Maximum points we can get starting from any city on day 0
        int maxPoints = 0;
        for (int startCity = 0; startCity < n; ++startCity) {
            int points = dfs(startCity, 0, n, k, stayScore, travelScore, memo);
            maxPoints = max(maxPoints, points);
        }
        return maxPoints;
    }

private:
    int dfs(int city, int day, int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore, vector<vector<int>>& memo) {
        // Base case: if day == k, vacation is over
        if (day == k) return 0;

        // Check if we already computed this state
        if (memo[city][day] != -1) return memo[city][day];

        // Choice 1: Stay in the same city
        int maxPoints = stayScore[day][city] + dfs(city, day + 1, n, k, stayScore, travelScore, memo);

        // Choice 2: Travel to another city
        for (int nextCity = 0; nextCity < n; ++nextCity) {
            if (nextCity != city) {
                int points = travelScore[city][nextCity] + dfs(nextCity, day + 1, n, k, stayScore, travelScore, memo);
                maxPoints = max(maxPoints, points);
            }
        }

        // Save and return the best score for this state
        return memo[city][day] = maxPoints;
    }
};
