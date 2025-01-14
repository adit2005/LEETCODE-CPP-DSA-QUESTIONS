class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        long long a = 0, b = 0, one = 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            a |= one << A[i];
            b |= one << B[i];
            ans[i] = __builtin_popcountll(a & b); // Count set bits
        }
        return ans;
    }
};