class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xSorted;
        for(const auto &point : points){
            xSorted.push_back(point[0]);
        }

        sort(xSorted.begin(), xSorted.end());

        int max_width = 0;
        for (int i = 0; i < xSorted.size() -1; i++){
            max_width = max(max_width, xSorted[i+1] - xSorted[i]);
        }

        return max_width;
    }
};