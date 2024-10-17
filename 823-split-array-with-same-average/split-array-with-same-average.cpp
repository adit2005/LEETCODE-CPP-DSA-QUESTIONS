class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), m = n / 2, totalSum = accumulate(A.begin(), A.end(), 0);
        
        // Early pruning step: Check if it's even possible to split the array.
        // We iterate over possible subset sizes (from 1 to m) and see if there is a subset of size 'i'
        // that can have a sum which is proportional to 'totalSum * i / n'.
        // This checks if 'totalSum * i' is divisible by 'n', meaning a subset of size 'i' could have the required sum.
        bool isPossible = false;
        for (int i = 1; i <= m && !isPossible; ++i) 
            if (totalSum * i % n == 0) isPossible = true;
        // If no such subset size is possible, return false early.
        if (!isPossible) return false;

        // DP like knapsack approach to find possible sums for subsets of different sizes.
        // Create a vector of sets where sums[i] stores all possible sums of subsets with size 'i'.
        vector<unordered_set<int>> sums(m + 1);
        sums[0].insert(0); // Initialize with an empty subset of size 0 with sum 0.

        // Iterate through each number in the array.
        for (int num : A) {
            // Iterate from 'm' down to '1' to prevent reusing the same number in the same iteration.
            // This ensures that we're adding 'num' to existing subsets rather than repeatedly using 'num' for the same subset size.
            for (int i = m; i >= 1; --i) {
                // For each possible sum 't' of subsets with size 'i-1', add 'num' to it to form new sums for subsets of size 'i'.
                for (const int t : sums[i - 1]) 
                    sums[i].insert(t + num);
            }
        }

        // Now, we check if there's a valid subset of size 'i' with the desired sum.
        // Iterate over all subset sizes from '1' to 'm'.
        for (int i = 1; i <= m; ++i) {
            // If a subset of size 'i' could have the sum 'totalSum * i / n' (which means its average matches the average of the whole array),
            // and if that sum exists in sums[i], we have found a valid split.
            if (totalSum * i % n == 0 && sums[i].find(totalSum * i / n) != sums[i].end()) 
                return true;
        }

        // If no valid subset is found, return false.
        return false;
    }
};
