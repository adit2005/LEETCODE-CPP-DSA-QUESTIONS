class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        int res = 0;

        for (int up = 0; up < M; ++up) {
            vector<int> h(N, 1);
            for (int down = up; down < M; ++down) {
                for (int k = 0; k < N; ++k) 
                    h[k] &= mat[down][k];
                
                res += countOneRow(h);
            }
        }

        return res;
    }

private:
    int countOneRow(vector<int>& A) {
        int res = 0, length = 0;
        for (int i = 0; i < A.size(); ++i) {
            length = (A[i] == 0 ? 0 : length + 1);
            res += length;
        }
        return res;
    }
};
