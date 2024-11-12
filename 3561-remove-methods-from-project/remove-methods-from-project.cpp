#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the invokes and invoked_by graphs
        unordered_map<int, vector<int>> invokes;
        unordered_map<int, vector<int>> invoked_by;

        for (auto& invocation : invocations) {
            int a = invocation[0], b = invocation[1];
            invokes[a].push_back(b);       // a invokes b
            invoked_by[b].push_back(a);     // b is invoked by a
        }

        // Step 2: Find all suspicious methods reachable from `k` using DFS
        unordered_set<int> suspicious_methods;
        stack<int> stk;
        stk.push(k);

        while (!stk.empty()) {
            int method = stk.top();
            stk.pop();
            if (suspicious_methods.count(method) == 0) {
                suspicious_methods.insert(method);
                for (int invoked : invokes[method]) {
                    if (suspicious_methods.count(invoked) == 0) {
                        stk.push(invoked);
                    }
                }
            }
        }

        // Step 3: Check if any method outside suspicious_methods invokes a suspicious method
        for (int method : suspicious_methods) {
            for (int invoker : invoked_by[method]) {
                if (suspicious_methods.count(invoker) == 0) {
                    // If an invoker outside the suspicious set is found, we can't remove anything
                    vector<int> all_methods(n);
                    for (int i = 0; i < n; ++i) all_methods[i] = i;
                    return all_methods;
                }
            }
        }

        // Step 4: Remove all suspicious methods and return the remaining methods
        vector<int> remaining_methods;
        for (int i = 0; i < n; ++i) {
            if (suspicious_methods.count(i) == 0) {
                remaining_methods.push_back(i);
            }
        }
        return remaining_methods;
    }
};
