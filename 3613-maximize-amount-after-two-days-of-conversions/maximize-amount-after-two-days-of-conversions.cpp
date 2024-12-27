class Solution {
public:
    // Helper function to perform Bellman-Ford algorithm
    unordered_map<string, double> bellmanFord(string start, vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, vector<pair<string, double>>> graph;
        unordered_map<string, double> maxAmount;

        // Build the graph
        for (int i = 0; i < pairs.size(); ++i) {
            string u = pairs[i][0], v = pairs[i][1];
            double rate = rates[i];
            graph[u].emplace_back(v, rate);
            graph[v].emplace_back(u, 1.0 / rate); // Add reverse edge
        }

        // Initialize max amounts
        for (auto& [currency, _] : graph) {
            maxAmount[currency] = 0.0;
        }
        maxAmount[start] = 1.0;

        // Relax edges |V|-1 times
        for (int i = 0; i < graph.size() - 1; ++i) {
            for (auto& [u, edges] : graph) {
                for (auto& [v, rate] : edges) {
                    maxAmount[v] = max(maxAmount[v], maxAmount[u] * rate);
                }
            }
        }

        return maxAmount;
    }

    // Main function to calculate the maximum amount
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        // Perform Bellman-Ford for Day 1
        unordered_map<string, double> day1Amounts = bellmanFord(initialCurrency, pairs1, rates1);

        // Perform Bellman-Ford for Day 2
        unordered_map<string, double> day2Amounts;
        for (auto& [currency, amount] : day1Amounts) {
            if (amount > 0.0) {
                unordered_map<string, double> tempAmounts = bellmanFord(currency, pairs2, rates2);
                for (auto& [nextCurrency, nextAmount] : tempAmounts) {
                    day2Amounts[nextCurrency] = max(day2Amounts[nextCurrency], amount * nextAmount);
                }
            }
        }

        // Return the maximum amount of the initial currency
        return day2Amounts[initialCurrency];
    }
};
