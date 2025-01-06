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

        // End at A[a][1]
        cur = 0;
        for (int a = 0, b = 0; a < n; ++a) {
            cur += 1L * (A[a][1] - A[a][0] + 1) * A[a][2];
            while (A[b][1] < A[a][1] - k + 1) {
                cur -= 1L * (A[b][1] - A[b][0] + 1) * A[b][2];
                b++;
            }
            long long part = 1L * max(0, A[a][1] - k - A[b][0] + 1) * A[b][2];
            res = max(res, cur - part);
        }

        return res;
    }
};
