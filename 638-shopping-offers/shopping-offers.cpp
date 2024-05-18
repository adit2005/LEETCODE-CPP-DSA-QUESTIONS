class Solution {
private:
    // Helper function to recursively calculate the minimum cost.
    int ex(int ind, vector<int> ds, vector<int> &price, vector<vector<int>> &offer, vector<int> &need, map<int, map<vector<int>, int>> &dp) {
        // Base case: if we have considered all offers.
        if (ind == offer.size()) {
            int tot = 0;
            // Calculate the total cost without any more offers.
            for (int i = 0; i < need.size(); i++) {
                tot += (need[i] - ds[i]) * price[i]; // Remaining items are bought at regular prices.
            }
            return tot;
        }
        
        // Check if we have already solved this subproblem.
        if (dp.find(ind) != dp.end() && dp[ind].find(ds) != dp[ind].end()) {
            return dp[ind][ds];
        }

        // Option 1: Do not take the current offer.
        int offer_notTake = ex(ind + 1, ds, price, offer, need, dp);

        int offer_take = 1e9; // Initialize the cost of taking the offer to a high value.
        vector<int> copyDS = ds; // Copy the current distribution status.

        // Try to take the current offer.
        for (int i = 0; i < need.size(); i++) {
            if (copyDS[i] + offer[ind][i] <= need[i]) {
                // Update the distribution status if the offer can be used.
                copyDS[i] += offer[ind][i];
            } else {
                // If the offer exceeds the need, skip this option.
                return dp[ind][ds] = min(offer_notTake, offer_take);
            }
        }
        // Add the cost of the current offer and recursively solve for the remaining needs.
        offer_take = offer[ind][price.size()] + ex(ind, copyDS, price, offer, need, dp);

        // Store the result in the memoization table and return the minimum cost.
        return dp[ind][ds] = min(offer_notTake, offer_take);
    }

public:
    // Main function to find the minimum cost to satisfy the needs.
    int shoppingOffers(vector<int>& price, vector<vector<int>>& offer, vector<int>& need) {
        map<int, map<vector<int>, int>> dp; // Memoization table to store intermediate results.
        vector<int> ds(need.size(), 0); // Initial distribution status (no items bought yet).
        return ex(0, ds, price, offer, need, dp); // Start the recursive calculation.
    }
};
