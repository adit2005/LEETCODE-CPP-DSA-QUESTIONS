class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1, i = n / 2, j = n, ans = 0;
        while(i >= 0 && j > n / 2) {
            if(nums[i] * 2 <= nums[j]) ans += 2, i--, j--;
            else i--;
        }
        return ans;
    }
};