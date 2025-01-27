class Solution {
    // Utility function to multiply two numbers
    long long mul(long long x, long long y) {
        return x * y;
    }
    
    // Depth-first search (DFS) function to calculate the contribution of each subtree
    pair<int, int> dfs(int x, int f, const vector<vector<int>> &con, const vector<bool> &prime, long long &r) {
        // `v` is a pair storing:
        // v.first -> Number of non-prime nodes in the subtree rooted at node `x`
        // v.second -> Number of prime nodes in the subtree rooted at node `x`
        pair<int, int> v = {!prime[x], prime[x]}; 
        
        // Traverse all neighbors of the current node `x`
        for (int y : con[x]) {
            // Skip the parent node to avoid going back in the tree
            if (y == f) continue;

            // Perform DFS for the child node `y` and get the counts of prime/non-prime nodes
            const auto& p = dfs(y, x, con, prime, r);

            // Calculate the number of valid paths between the current subtree and its parent
            // Paths are formed when:
            // - A non-prime node in the current subtree pairs with a prime node in another subtree
            // - A prime node in the current subtree pairs with a non-prime node in another subtree
            r += mul(p.first, v.second) + mul(p.second, v.first);

            // Update the counts for the current node `x`
            if (prime[x]) {
                // If the current node is prime, it adds the non-prime nodes from the child subtree
                v.second += p.first;
            } else {
                // If the current node is non-prime, it adds both prime and non-prime counts from the child subtree
                v.first += p.first;
                v.second += p.second;
            }
        }
        return v;
    }
    
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        // Step 1: Sieve of Eratosthenes to mark prime numbers up to `n`
        vector<bool> prime(n + 1, true);
        prime[1] = false; // 1 is not a prime number
        vector<int> all;  // To store all prime numbers
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                all.push_back(i); // Add prime number `i` to the list
            }
            for (int x : all) {
                const int temp = i * x;
                if (temp > n) break; // Stop if we exceed `n`
                prime[temp] = false; // Mark composite number
                if (i % x == 0) break; // Stop if `i` is divisible by `x`
            }
        }

        // Step 2: Build the adjacency list for the tree
        vector<vector<int>> con(n + 1);
        for (const auto& e : edges) {
            con[e[0]].push_back(e[1]);
            con[e[1]].push_back(e[0]);
        }

        // Step 3: Initialize the result variable to store the total number of valid paths
        long long r = 0;

        // Step 4: Perform DFS starting from node 1
        dfs(1, 0, con, prime, r);

        // Step 5: Return the total number of valid paths
        return r;
    }
};
