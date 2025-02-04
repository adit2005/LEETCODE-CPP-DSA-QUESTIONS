class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            int val = edges[i];
            if (val != -1) {
                indegree[val]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Remove all nodes which will never be the part of a cycle and this can
        // be done using toposort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int val = edges[node];
            if (val != -1) {
                indegree[val]--;
                if (indegree[val] == 0)
                    q.push(val);
            }
        }

        // After removing the nodes, we can have multiple cycle, so find the
        // length of maximum cycle
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] >= 1) {
                ans = max(ans, dfs(indegree, edges, i));
            }
        }

        if (ans == 0)
            return -1;
        else
            return ans + 1;
    }

    int dfs(vector<int>& indegree, vector<int>& edges, int i) {
        indegree[i]--;
        int val = edges[i];
        int cnt = 0;
        if (val != -1 && indegree[val] >= 1) {
            cnt = 1 + dfs(indegree, edges, val);
        }

        return cnt;
    }
};