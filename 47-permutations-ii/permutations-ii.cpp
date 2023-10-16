class Solution {
    private:
    void permuteUnique(vector<int>&nums, vector<vector<int>>& result, vector<int> temp, vector<bool> &visited){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i] || i>0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            permuteUnique(nums, result, temp, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(nums.size(), 0);
        permuteUnique(nums, result, temp, visited);
        return result;
    }
};