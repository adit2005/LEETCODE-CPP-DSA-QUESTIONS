class Solution {
public:
    vector<list<int>> graph;
    int dfs(int curr, int par, vector<int>& size) {
        int sz = 1;
        for(int nbr : graph[curr]){
            if(nbr != par) sz += dfs(nbr, curr, size);
        }
        size[curr] = sz;
        return sz;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        graph.clear();
        graph.resize(n);
        vector<int> size(n, 0);
        for(int i = 0; i < n-1; i++){
            graph[edges[i][1]].push_back(edges[i][0]);
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        dfs(0, -1, size);
        int res = 0;

        for(int i = 0; i < n; i++){
            bool flag = true;
            int prev = -1;
            for(auto nbr : graph[i]) {
                if(size[nbr] < size[i]){
                    if(prev == -1) prev = size[nbr];
                    else if(prev != size[nbr]) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) res++;
        }

        return res;
    }
};