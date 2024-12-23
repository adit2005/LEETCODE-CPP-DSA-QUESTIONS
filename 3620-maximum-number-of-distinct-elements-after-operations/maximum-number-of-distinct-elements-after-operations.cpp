class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        
        int prev = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            int curr = max(prev + 1, nums[i] - k);

            if(curr <= nums[i] + k) {
                prev = curr;
                cnt += 1;
            }
        }

        return cnt;
    }
};