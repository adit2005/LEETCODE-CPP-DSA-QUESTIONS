class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }
        
        unordered_map<int,int> map;
        for (int num : nums) {
            map[num]++;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int num : nums) {
            if (map[num] > 0) {
                for (int i = num + 1; i < num + k; i++) {
                    if (map[i] == 0) {
                        return false;
                    }
                    map[i]--;
                }
                map[num]--;
            }
        }
        
        return true;
    }
};