class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> dp(n2 + 1,0), dpPrev(n2 + 1,0);

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = max(dp[j - 1], dpPrev[j]);
                }
            }
            dpPrev = dp; // Update dpPrev with the values of dp for the next iteration
        }

        return dp[n2]; // Return the value of dp at the end
    }
};
