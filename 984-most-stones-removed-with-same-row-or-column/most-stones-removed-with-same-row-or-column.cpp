class Solution {
private:
    vector<int> parent;

    int find(int n) { return parent[n] == n ? n : parent[n] = find(parent[n]); }

    void unite(int a, int b) { parent[find(b)] = find(a); }

public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rowmap, colmap;
        parent.resize(stones.size());

        for (int i = 0; i < stones.size(); i++) {
            rowmap[stones[i][0]].push_back(i);
            colmap[stones[i][1]].push_back(i);
            parent[i] = i;
        }

        for (int i = 0; i < stones.size(); i++) {
            for (int j : rowmap[stones[i][0]]) unite(i, j);
            for (int j : colmap[stones[i][1]]) unite(i, j);
        }

        unordered_set<int> unique;
        for (int n : parent) unique.insert(find(n));
        return stones.size() - unique.size();
    }
};
