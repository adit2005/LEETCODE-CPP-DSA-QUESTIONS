class Solution {
public:
    int minDeletion(vector<int>& A) {
        int i = 0, N = A.size(), ans = 0;
        for (; i < N; i += 2) {
            while (i + 1 < N && A[i] == A[i + 1]) ++i, ++ans; 
            if (i + 1 == N) ++ans; // can't find a pair, delete `A[i]
        }
        return ans;
    }
};