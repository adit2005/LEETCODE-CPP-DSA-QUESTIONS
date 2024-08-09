class Solution {
public:
    int numTilings(int n) {
        // DP table to store intermediate results, initialized to -1
        vector<vector<long>> t(n + 1, vector<long>(n + 1, -1));
        // Start DFS from the top-left corner of the board
        return dfs(0, 0, t);
    }

    long dfs(int x, int y, vector<vector<long>>& t){
        // Base case: If we have reached the end of both rows, we have a valid tiling
        if (x == t.size() - 1 && y == t.size() - 1) return 1;

        // If either x or y goes out of bounds, return 0 (invalid tiling)
        if (x >= t.size() || y >= t.size()) return 0;

        // If this state has already been computed, return the stored result
        if (t[x][y] != -1) return t[x][y];

        long sum = 0;

        // Case 1: If x and y are different, consider the possibility of adding a 1x2 domino
        // If x < y, add a domino to row y; if x > y, add a domino to row x
        if (x != y){
            if (x < y)
                sum += dfs(x + 2, y, t);
            else    
                sum += dfs(x, y + 2, t);
        }
        else {
            // Case 2: If x == y, we have several options:
            // (a) Add two dominoes, one to each row
            sum += dfs(x + 2, y + 2, t);
            
            // (b) Add one domino vertically, covering both rows
            sum += dfs(x + 1, y + 1, t);
            
            // (c) Add an L-shaped tromino covering (x, x+1) and y+2 or x+2 and y+1
            sum += dfs(x + 1, y + 2, t);
            sum += dfs(x + 2, y + 1, t);
        }

        // Additional checks for L-shaped trominoes:
        // (d) If the gap between x and y is exactly 1, try adding an L-shaped tromino
        if (y + 1 == x + 2) sum += dfs(x + 2, y + 1, t);
        if (x + 1 == y + 2) sum += dfs(x + 1, y + 2, t);

        // Store the computed result in the DP table, modulo 1000000007
        return t[x][y] = sum % 1000000007;
    }
};
