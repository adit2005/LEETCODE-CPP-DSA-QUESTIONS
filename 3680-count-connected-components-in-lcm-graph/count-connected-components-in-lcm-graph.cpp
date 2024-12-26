class DSU {
public:
    vector<int> parent, rank;

    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;
    }

    int find(int node) {
        return parent[node] = (parent[node] == node ? node : find(parent[node]));
    }

    bool unite(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 != root2) {
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                if (rank[root1] == rank[root2]) rank[root1]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int calculateLCM(int a, int b) {
        return (a / __gcd(a, b)) * b;
    }

    int countComponents(vector<int>& nums, int threshold) {
        int componentCount = 0;
        sort(nums.begin(), nums.end());

        while (!nums.empty() && nums.back() > threshold) {
            componentCount++;
            nums.pop_back();
        }

        if (nums.empty()) return componentCount;

        int n = nums.size();
        DSU dsu(n);
        unordered_map<int, int> divisorMap;

        for (int i = 0; i < n; i++) {
            for (int divisor = 1; divisor * divisor <= nums[i]; divisor++) {
                if (nums[i] % divisor == 0) {
                    if (divisorMap.count(divisor)) {
                        int otherIdx = divisorMap[divisor];
                        if (calculateLCM(nums[i], nums[otherIdx]) <= threshold) {
                            dsu.unite(i, otherIdx);
                        }
                    } else {
                        divisorMap[divisor] = i;
                    }

                    int quotient = nums[i] / divisor;
                    if (quotient != divisor) {
                        if (divisorMap.count(quotient)) {
                            int otherIdx = divisorMap[quotient];
                            if (calculateLCM(nums[i], nums[otherIdx]) <= threshold) {
                                dsu.unite(i, otherIdx);
                            }
                        } else {
                            divisorMap[quotient] = i;
                        }
                    }
                }
            }
        }

        unordered_set<int> uniqueComponents;
        for (int i = 0; i < n; i++) {
            uniqueComponents.insert(dsu.find(i));
        }

        return componentCount + uniqueComponents.size();
    }
};