class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // support variables
        int res = 0;
        unordered_map<int, int> m;
        // main loop
        for (int n: nums) {
            if (m[k - n] > 0) {
                m[k - n]--;
                res++;
            }
            else m[n]++;
        }
        return res;
    }
};