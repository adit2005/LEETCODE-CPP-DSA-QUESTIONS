class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> temp;
        vector<vector<int>> result;

        for(int i = 0; i< groupSizes.size(); i++){
            int size = groupSizes[i];
            temp[size].push_back(i);

            if(temp[size].size() == size){
                result.push_back(temp[size]);
                temp[size].clear();
            }
        }
        return result;
    }
};