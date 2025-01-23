class DisjointSet {
    public : 
        vector<int> parent,size;
        DisjointSet(int n) {
            parent.resize(n+1);
            size.resize(n+1);

            for(int i=0;i<=n;i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if(parent[node] == node)
                return node;

            return parent[node] = findUPar(parent[node]);
        }


        void unionBySize(int u,int v) {
            int ultU = findUPar(u);
            int ultV = findUPar(v);

            if(ultU == ultV)
                return;

            if(size[ultU] < size[ultV]) {
                parent[ultU] = ultV;
                size[ultV] += size[ultU];
                size[ultU] = 0;
            }
            else {
            parent[ultV] = ultU;
            size[ultU] += size[ultV];  
            size[ultV] = 0;
        }
        }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxRow = n-1,maxCol = m-1;

        DisjointSet ds(n*m);

        for(int row=0;row<n;row++) {
            for(int col=0;col<m;col++) {
                if(grid[row][col] == 1) {
                    int cellInd = row*m + col;

                    while(col < m) {
                        if(grid[row][col] == 1) {
                            int neighCellInd = row*m + col;

                            ds.unionBySize(cellInd,neighCellInd);
                        }
                        col++;
                    }
                }
            }
        }


        for(int col = 0;col<m;col++) {
            for(int row = 0;row<n;row++) {
                if(grid[row][col] == 1) {
                    int cellInd = row*m + col;
                    while(row < n) {
                        if(grid[row][col] == 1) {
                            int neighCellInd = row*m + col;
                            ds.unionBySize(cellInd,neighCellInd);
                        }
                        row++;
                    }
                }
            }
        }

        int count = 0;

        for(int i=0;i<=(n*m);i++) {
            if(ds.size[i] > 1) {
                count += ds.size[i];
            }
        }


        return count;
    }
};