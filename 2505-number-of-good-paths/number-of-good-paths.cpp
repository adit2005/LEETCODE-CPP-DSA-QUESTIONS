class UnionFind {
public:
    vector<int> parent, size;

    UnionFind(int n) {
        parent.resize(n, -1);
        size.resize(n, 1);
    }

    int find(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u]);
    }

    bool unionBySize(int u, int v) {
        u = find(u);
        v = find(v);

        if(u != v) {
            if(size[u]<size[v]) swap(u,v);
            parent[v] = u;
            size[u] += size[v];
            return true;
        }

        return false;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int n = vals.size();

        // create an adjacency list
        vector<vector<int>> AList(n);

        for(vector<int>& edge : edges) {
            AList[edge[0]].push_back(edge[1]);
            AList[edge[1]].push_back(edge[0]);
        }

        // group all the nodes that
        // have the same value together
        map<int,vector<int>> mp;

        for(int i=0; i<n; i++) {
            mp[vals[i]].push_back(i);
        }
        
        UnionFind uf(n);

        long long result = 0;

        for(auto& [val, nodes] : mp) {
            // add the edges to union find
            for(int u : nodes) {
                // we can add the edge only 
                // if its value is less than or 
                // equal to val, or else it will be invalid
                for(int v : AList[u]) {
                    if(vals[v] <= val) uf.unionBySize(u, v);
                }
            }

            // find the number of nodes
            // in each component
            unordered_map<int,int> comps;
            

            for(int u : nodes) {
                comps[uf.find(u)]++;
            }

            // go through the individual components
            // and find the good paths
            for(auto& [p, size] : comps) {
                result += (size*(size+1))/2;
            }
        }
        
        return result;
    }
};