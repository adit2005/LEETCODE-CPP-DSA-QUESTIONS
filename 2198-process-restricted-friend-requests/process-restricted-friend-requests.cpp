class UnionFind {
public:
    vector<int> parent;

    // Constructor to initialize the union-find structure
    UnionFind(int n) {
        parent.resize(n + 1, -1);
    }

    // Find function with path compression
    int find(int x) {
        int root = x;
        // Find the root of the set containing x
        while (parent[root] >= 0) {
            root = parent[root];
        }

        // Path compression: make all nodes in the path point directly to the root
        while (parent[x] >= 0) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }

        return root;
    }

    // Union function to merge two sets
    void unionz(int x, int y) {
        int root1 = find(x);
        int root2 = find(y);

        // If both elements are in the same set, no need to union
        if (root1 == root2)
            return;

        // Union by size: attach the smaller tree under the larger tree
        if (parent[root1] < parent[root2]) {
            parent[root1] += parent[root2];
            parent[root2] = root1;
        } else {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
    }
};


class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<bool> ans(m, 0);
        
        UnionFind UF(n);
        
        // Iterate through each friend request
        for (int i = 0; i < m; i++) {
            // Create a temporary union-find structure to test the current request
            UnionFind temp = UF;
            temp.unionz(requests[i][0], requests[i][1]);
            bool flag = true;

            // Check if the union violates any restriction
            for (vector<int>& v : restrictions) {
                if (temp.find(v[0]) == temp.find(v[1])) {
                    flag = false;  // A restriction is violated
                    break;
                }
            }
            
            // If no restrictions are violated, approve the request
            if (flag) {
                ans[i] = true;
                UF.unionz(requests[i][0], requests[i][1]);
            }
        }
        
        return ans;
    }
};
