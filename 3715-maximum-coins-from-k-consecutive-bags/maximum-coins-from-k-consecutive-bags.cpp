class Solution {
public:
        long long maximumCoins(vector<vector<int>>& A, int k) {
        sort(A.begin(), A.end());
        int n = A.size();

        // Start at A[i][0]
        long long res = 0, cur = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && A[j][1] <= A[i][0] + k - 1) {
                cur += 1L * (A[j][1] - A[j][0] + 1) * A[j][2];
                j++;
            }
            if (j < n) {
                long long part = 1L * max(0, A[i][0] + k - 1 - A[j][0] + 1) * A[j][2];
                res = max(res, cur + part);
            }
            cur -= 1L * (A[i][1] - A[i][0] + 1) * A[i][2];
        }

        // End at A[i][1]
        cur = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            cur += 1L * (A[i][1] - A[i][0] + 1) * A[i][2];
            while (A[j][1] < A[i][1] - k + 1) {
                cur -= 1L * (A[j][1] - A[j][0] + 1) * A[j][2];
                j++;
            }
            long long part = 1L * max(0, A[i][1] - k - A[j][0] + 1) * A[j][2];
            res = max(res, cur - part);
        }

        return res;
    }
};