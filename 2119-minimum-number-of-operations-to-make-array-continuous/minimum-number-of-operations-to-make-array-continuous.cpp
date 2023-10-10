class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        vector<int> v;
        int mini = n;
        for (int num : s) {
            v.push_back(num);
        }
        int j = 0;
        for (int i = 0; i < v.size(); i++) {
            while (j < v.size() && v[j] < v[i] + n) {
                j++;
            }
            int count = j - i;
            mini= min(mini, n - count);
        }
        return mini;
    }
};