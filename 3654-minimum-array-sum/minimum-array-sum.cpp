class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();

        // Initialize a 3D DP array with INT_MAX as default values
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, INT_MAX)));

        // Base case: when idx == n, the sum is 0 regardless of remaining operations
        for (int i = 0; i <= op1; i++) {
            for (int j = 0; j <= op2; j++) {
                dp[n][i][j] = 0;
            }
        }

        // Fill DP table bottom-up
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int remainingOp1 = 0; remainingOp1 <= op1; remainingOp1++) {
                for (int remainingOp2 = 0; remainingOp2 <= op2; remainingOp2++) {
                    int ans = INT_MAX;

                    // CASE-1: Apply only Operation-1
                    if (remainingOp1 > 0) {
                        int sumOp1 = (nums[idx] + 1) / 2 + dp[idx + 1][remainingOp1 - 1][remainingOp2];
                        ans = min(ans, sumOp1);
                    }

                    // CASE-2: Apply only Operation-2
                    if (remainingOp2 > 0 && nums[idx] >= k) {
                        int sumOp2 = (nums[idx] - k) + dp[idx + 1][remainingOp1][remainingOp2 - 1];
                        ans = min(ans, sumOp2);
                    }

                    // CASE-3: Apply Operation-1, then Operation-2
                    if (remainingOp1 > 0 && remainingOp2 > 0) {
                        int afterOp1 = (nums[idx] + 1) / 2;
                        if (afterOp1 >= k) {
                            int sumOp1Op2 = (afterOp1 - k) + dp[idx + 1][remainingOp1 - 1][remainingOp2 - 1];
                            ans = min(ans, sumOp1Op2);
                        }
                    }

                    // CASE-4: Apply Operation-2, then Operation-1
                    if (remainingOp1 > 0 && remainingOp2 > 0 && nums[idx] >= k) {
                        int sumOp2Op1 = ((nums[idx] - k + 1) / 2) + dp[idx + 1][remainingOp1 - 1][remainingOp2 - 1];
                        ans = min(ans, sumOp2Op1);
                    }

                    // CASE-5: Don't apply any operation
                    int sumNoOp = nums[idx] + dp[idx + 1][remainingOp1][remainingOp2];
                    ans = min(ans, sumNoOp);

                    dp[idx][remainingOp1][remainingOp2] = ans;
                }
            }
        }

        // Return the result from the starting state
        return dp[0][op1][op2];
    }
};
