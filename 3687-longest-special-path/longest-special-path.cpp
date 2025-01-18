class Solution {
public:
    int maxLength = 0, minNodes = INT_MAX;

    void dfs(int node, int parent, vector<vector<pair<int, int>>>& gr, vector<int>& nums, int pathSum, int start, int end, 
             unordered_map<int, int>& depthMap, vector<int>& path) {
        int prevDepth = depthMap.count(nums[node]) ? depthMap[nums[node]] : -1;
        while (start <= prevDepth) {
            pathSum -= path[start++];
        }
        if (pathSum > maxLength) {
            maxLength = pathSum;
            minNodes = end - start + 1;
        } else if (pathSum == maxLength) {
            minNodes = min(minNodes, end - start + 1);
        }

        depthMap[nums[node]] = end;
        for (auto& [neighbor, weight] : gr[node]) {
            if (neighbor != parent) {
                path.push_back(weight);
                dfs(neighbor, node, gr, nums, pathSum + weight, start, end + 1, depthMap, path);
                path.pop_back();
            }
        }
        depthMap[nums[node]] = prevDepth;
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> gr(n);
        for (auto& edge : edges) {
            gr[edge[0]].emplace_back(edge[1], edge[2]);
            gr[edge[1]].emplace_back(edge[0], edge[2]);
        }
        unordered_map<int, int> depthMap;
        vector<int> path = {};
        dfs(0, -1, gr, nums, 0, 0, 0, depthMap, path);
        return {maxLength, minNodes};
    }
};