class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& A, long long k) {
        // Step 1: Reverse the array to simplify handling non-decreasing subarrays
        reverse(A.begin(), A.end());

        long long res = 0; // To store the final result (count of valid subarrays)
        deque<int> q; // Monotonic deque to store indices of array elements
        for (int j = 0, i = 0; j < A.size(); ++j) {
            // Maintain the monotonicity of the deque (non-decreasing order)
            while (!q.empty() && A[q.back()] < A[j]) {
                // Remove elements from the back of the deque if they break monotonicity
                int r = q.back(); // Current element to be removed
                q.pop_back(); // Remove it from the deque
                // Find the previous element's index in the deque or assume `i - 1`
                int l = q.empty() ? i - 1 : q.back();
                // Adjust `k` to account for the reduction in the difference sums
                k -= 1L * (r - l) * (A[j] - A[r]);
            }

            // Add the current index to the deque
            q.push_back(j);

            // Adjust the left bound (`i`) of the sliding window if `k` becomes negative
            while (k < 0) {
                // Increase `k` by the contribution of the current element at `i`
                k += A[q.front()] - A[i];
                // If the front element of the deque is the same as `i`, remove it
                if (q.front() == i) {
                    q.pop_front();
                }
                // Move the left pointer of the sliding window to the right
                ++i;
            }

            // Add the count of valid subarrays ending at index `j`
            res += j - i + 1;
        }
        return res; // Return the total count of valid subarrays
    }
};
