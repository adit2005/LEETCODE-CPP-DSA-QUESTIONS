class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        
        // Step 1: Handle k == 0 case
        if (k == 0) {
            return vector<int>(n, 0);
        }

        // Step 2: Extend the array to handle circularity
        vector<int> extendedCode(2 * n);
        for (int i = 0; i < n; ++i) {
            extendedCode[i] = code[i];
            extendedCode[i + n] = code[i];
        }

        // Step 3: Calculate prefix sum of the extended array
        vector<int> prefixSum(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + extendedCode[i];
        }

        // Step 4: Compute the result
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                // Sum of next k elements
                result[i] = prefixSum[i + k + 1] - prefixSum[i + 1];
            } else {
                // Sum of previous |k| elements
                result[i] = prefixSum[i + n] - prefixSum[i + n + k];
            }
        }

        return result;
    }
};
