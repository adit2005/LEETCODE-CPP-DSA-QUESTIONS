class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Stack-like list to store cumulative sums and their indices
        vector<pair<long long, int>> cumulativeSumStack;
        cumulativeSumStack.emplace_back(0LL, -1);

        long long runningCumulativeSum = 0;
        int shortestSubarrayLength = INT_MAX;

        for (int i = 0; i < n; i++) {
            // Update cumulative sum
            runningCumulativeSum += nums[i];

            // Remove entries from stack that are larger than current cumulative
            // sum
            while (!cumulativeSumStack.empty() &&
                   runningCumulativeSum <= cumulativeSumStack.back().first) {
                cumulativeSumStack.pop_back();
            }

            // Add current cumulative sum and index to stack
            cumulativeSumStack.emplace_back(runningCumulativeSum, i);

            int candidateIndex = findCandidateIndex(cumulativeSumStack,
                                                    runningCumulativeSum - k);

            // If a valid candidate is found, update the shortest subarray
            // length
            if (candidateIndex != -1) {
                shortestSubarrayLength =
                    min(shortestSubarrayLength,
                        i - cumulativeSumStack[candidateIndex].second);
            }
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }

private:
    // Binary search to find the largest index where cumulative sum is <= target
    int findCandidateIndex(const vector<pair<long long, int>>& nums,
                           long long target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid].first <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};