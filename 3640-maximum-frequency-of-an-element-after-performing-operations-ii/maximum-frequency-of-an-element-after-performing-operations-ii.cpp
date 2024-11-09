class Solution {
public:
    int maxFrequency(vector<int>& A, int k, int numOperations) {
        sort(A.begin(), A.end());

        // Populate the frequency map before Case 1
        unordered_map<int, int> count;
        for (int a : A) {
            count[a]++;
        }

        // Case 1
        int res = 0, i = 0, j = 0, n = A.size();
        for (int a : A) {
            while (j < n && A[j] <= a + k) {
                j++;
            }
            while (i < n && A[i] < a - k) {
                i++;
            }
            // Use the pre-populated frequency map instead of updating during the loop
            int cur = min(j - i, count[a] + numOperations);
            res = max(res, cur);
        }

        // Case 2
        for (int i = 0, j = 0; j < n; j++) {
            while (A[i] + k + k < A[j]) {
                i++;
            }
            res = max(res, min(j - i + 1, numOperations));
        }
        
        return res;
    }
};
