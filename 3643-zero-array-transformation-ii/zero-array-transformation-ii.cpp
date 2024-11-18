class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        int sum = 0;
        int k = 0;
        for (int i = 0; i < n; i++) {
            while (sum + cnt[i] < nums[i]) {
                k++;
                if (k  > queries.size()) return -1;
                int l = queries[k - 1][0];
                int r = queries[k - 1][1];
                int val = queries[k - 1][2];
                
                if (r < i) continue;
                cnt[max(l, i)] += val;
                cnt[r + 1] -= val;
            }
            sum += cnt[i];
        }
        return k;
    }
};