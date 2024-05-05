class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> xr;
    vector<vector<pair<int, char>>> graph;

    void dfs(int u, int mask) {
        mp[mask]++;
        xr[u] = mask;

        for (auto v : graph[u]) {
            int id = v.second - 'a';
            dfs(v.first, mask ^ (1 << id));
        }
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        graph.resize(n);
        xr.resize(n);

        for (int i = 1; i < n; i++) {
            int u = parent[i];
            int v = i;
            graph[u].push_back({v, s[i]});
        }

        dfs(0, 0);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                int msk = xr[i] ^ (1 << j);
                ans += mp[msk];
            }

            ans += mp[xr[i]] - 1;
        }

        return ans / 2;
    }
};
