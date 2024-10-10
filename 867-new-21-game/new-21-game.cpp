#include <vector>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // If k is 0 or n >= k + maxPts, Alice is guaranteed to have points <= n.
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;  // Starting point.
        double Wsum = 1.0;  // Sliding window sum for dp[0] initially.
        double result = 0.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = Wsum / maxPts;
            
            // Only add dp[i] to the result if i >= k, which means Alice has stopped drawing.
            if (i < k) {
                Wsum += dp[i];
            } else {
                result += dp[i];
            }
            
            // Slide the window by removing the effect of dp[i - maxPts] if i >= maxPts.
            if (i >= maxPts) {
                Wsum -= dp[i - maxPts];
            }
        }

        return result;
    }
};
