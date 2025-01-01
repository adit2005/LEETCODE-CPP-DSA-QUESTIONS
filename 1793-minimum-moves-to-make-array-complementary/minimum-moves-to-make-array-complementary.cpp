class Solution {
public:
    int s[200002]; // sweep array
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n/2; i++) {
            int small = min(nums[i],nums[n-1-i]);
            int big = max(nums[i], nums[n-1-i]);
            reach = max(reach, small+big);
            // Everything gets default 2 moves, subtract off moves
            // if we don't need to take it
            s[1] += 2;
            s[small+1]--;
            s[small+big]--;
            s[small+big+1]++;
            s[big+limit+1]++;
        }
        reach = max(reach, limit*2);
        int ans = INT_MAX;
        for (int i = 2; i <= reach; i++) {
            s[i] += s[i-1];
            ans = min(ans, s[i]);
        }
        return ans;
    }
};