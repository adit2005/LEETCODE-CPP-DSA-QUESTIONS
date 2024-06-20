class Solution {
public:
    const int MOD = 1000000007;

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));

        // Base case: If the current city is the finish city, there's at least one way to stay there with any fuel
        for (int f = 0; f <= fuel; ++f) {
            dp[finish][f] = 1;
        }

        // Fill the table
        for (int remainFuel = 0; remainFuel <= fuel; ++remainFuel) {
            for (int city = 0; city < n; ++city) {
                for (int nextCity = 0; nextCity < n; ++nextCity) {
                    if (nextCity != city) {
                        int cost = abs(locations[nextCity] - locations[city]);
                        if (remainFuel >= cost) {
                            dp[city][remainFuel] = (dp[city][remainFuel] + dp[nextCity][remainFuel - cost]) % MOD;
                        }
                    }
                }
            }
        }

        // Return the number of ways to go from the start city with all the fuel available
        return dp[start][fuel];
    }
};
