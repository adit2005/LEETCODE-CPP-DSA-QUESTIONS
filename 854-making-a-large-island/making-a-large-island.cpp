class DisjointSet {  
public:
    vector<int> rank, parent, size;

    // Constructor initializes the DisjointSet with n elements.
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 

        // Initially, each node is its own parent, and size is 1.
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    // Find the ultimate parent (with path compression).
    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    // Union by size, merging smaller set into the larger one.
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 

        if(ulp_u == ulp_v) return; // They are already in the same set.
        
        // Union by size: attach smaller tree under larger tree.
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n); // Disjoint set for n*n grid elements.

        // Directions for exploring neighbors: up, right, down, left.
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // Step 1: Union all adjacent '1's.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; k++) { // Check all four directions.
                        int nr = i + dr[k]; // Neighbor row.
                        int nc = j + dc[k]; // Neighbor column.

                        // Check if neighbor is within bounds and is '1'.
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int nodeno = n * i + j; // Current node number.
                            int adjno = n * nr + nc; // Adjacent node number.
                            ds.unionBySize(adjno, nodeno); // Union the two nodes.
                        }
                    }
                }
            }
        }

        // // Step 2: Find the maximum component size.
         int ans = 1; // At least one land is possible.
        for(int i = 0; i < n * n; i++) {
            ans = max(ans, ds.size[i]); // Find the largest component size.
        }

        // Step 3: Try converting each '0' to '1' and calculate the potential island size.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> st; // To store unique component representatives.
                    for(int k = 0; k < 4; k++) { // Check all four directions.
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        // Check if neighbor is within bounds and is '1'.
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int adjno = n * nr + nc;
                            st.insert(ds.findUPar(adjno)); // Insert the component representative.
                        }
                    }

                    int temps = 1; // Start with size 1 (the flipped '0' itself).
                    for(auto it: st) {
                        temps += ds.size[it]; // Add sizes of all unique neighboring components.
                    }
                    ans = max(ans, temps); // Update maximum possible island size.
                }
            }
        }

        return ans; // Return the largest possible island size.
    }
};
