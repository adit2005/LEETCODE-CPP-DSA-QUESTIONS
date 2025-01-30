#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        int res = 0;
        vector<int> h(N, 0);

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                h[j] = (mat[i][j] == 0 ? 0 : h[j] + 1);
            }
            res += helper(h);
        }

        return res;
    }

private:
    int helper(vector<int>& A) {
        int n = A.size();
        vector<int> sum(n, 0);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && A[st.top()] >= A[i]) 
                st.pop();

            if (!st.empty()) {
                int preIndex = st.top();
                sum[i] = sum[preIndex] + A[i] * (i - preIndex);
            } else {
                sum[i] = A[i] * (i + 1);
            }

            st.push(i);
        }

        int res = 0;
        for (int s : sum) res += s;
        
        return res;
    }
};
