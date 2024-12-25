class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1; // Means 1 point only available...
        int ans = 0;
        for(int i = 0; i < points.size(); ++i){
            unordered_map <double, int> mapping; // for store value of thetas...
            for(int j = 0; j < points.size(); ++j){
                if(j == i) continue; //skip kr do...
                auto dy = points[j][1] - points[i][1]; // (y2 - y1)...
                auto dx = points[j][0] - points[i][0]; // (x2 - x1)...
                // find theta = tan^-1(dy / dx)...
                auto theta = atan2(dy, dx); // cpp stl for finding tan^-1...
                mapping[theta]++;
            }
            for(auto &it : mapping){
                ans = max(ans, it.second + 1);
            }
        }
        return ans;
    }
};