class Solution {
public:
   
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int x, int y) {
        vector<vector<int>> ans;
        int total = rows * cols, count = 0, width = 1, height = 1;
        
        while (count < total) {
            // Move right
            for (int i = 0; i < width; ++i) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans.push_back({x, y});
                    ++count;
                }
                ++y;
            }
            ++width;
            
            // Move down
            for (int i = 0; i < height; ++i) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans.push_back({x, y});
                    ++count;
                }
                ++x;
            }
            ++height;
            
            // Move left
            for (int i = 0; i < width; ++i) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans.push_back({x, y});
                    ++count;
                }
                --y;
            }
            ++width;
            
            // Move up
            for (int i = 0; i < height; ++i) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans.push_back({x, y});
                    ++count;
                }
                --x;
            }
            ++height;
        }
        
        return ans;
    }
};