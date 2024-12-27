using namespace std;

class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        auto graph1 = buildGraph(pairs1, rates1);
        auto graph2 = buildGraph(pairs2, rates2);

        auto maxDay1 = bfs(initialCurrency, graph1);

        double maxCurrency = 0.0;
        for (auto& [currency, amount] : maxDay1) {
            auto maxDay2 = bfs(currency, graph2, amount);
            maxCurrency = max(maxCurrency, maxDay2[initialCurrency]);
        }

        return maxCurrency;
    }

private:
    unordered_map<string, vector<pair<string, double>>> buildGraph(vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < pairs.size(); ++i) {
            string from = pairs[i][0];
            string to = pairs[i][1];
            double rate = rates[i];
            graph[from].emplace_back(to, rate);
            graph[to].emplace_back(from, 1.0 / rate); 
        }
        return graph;
    }

    unordered_map<string, double> bfs(string start, unordered_map<string, vector<pair<string, double>>>& graph, double startAmount = 1.0) {
        unordered_map<string, double> maxAmount;
        queue<pair<string, double>> q;
        q.push({start, startAmount});
        maxAmount[start] = startAmount;

        while (!q.empty()) {
            auto [current, amount] = q.front();
            q.pop();

            for (auto& [neighbor, rate] : graph[current]) {
                double newAmount = amount * rate;
                if (newAmount > maxAmount[neighbor]) {
                    maxAmount[neighbor] = newAmount;
                    q.push({neighbor, newAmount});
                }
            }
        }

        return maxAmount;
    }
};