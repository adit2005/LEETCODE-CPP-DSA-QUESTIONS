class Solution {
public:
    // Function to determine the minimum number of moves required
    // to make all the sums of pairs in nums be less than or equal to limit
    int minMoves(std::vector<int>& nums, int limit) {
        int n = nums.size(); // Number of elements in nums
        vector<int> delta(limit * 2 + 2, 0); // Array to track the changes in moves
      
        // Calculate the change in moves for each pair
        for (int i = 0; i < n / 2; ++i) {
            int lower = std::min(nums[i], nums[n - i - 1]); // Lower of the pair
            int upper = std::max(nums[i], nums[n - i - 1]); // Upper of the pair

            // Increment by two for the worst case (both need to change)
            delta[2] += 2;
            delta[limit * 2 + 1] -= 2;

            // Decrement by one as at least one of the numbers need to change
            delta[lower + 1] -= 1;
            delta[upper + limit + 1] += 1;

            // No operation needed when the sum equals lower+upper
            delta[lower + upper] -= 1;
            delta[lower + upper + 1] += 1;
        }
      
        int minMoves = n; // Start with the worst case moves count
        int currentMoves = 0; // Initialize a counter for the current moves
      
        // Accumulate the delta values and find the minimum moves
        for (int i = 2; i <= limit * 2; ++i) {
            currentMoves += delta[i];
            if (minMoves > currentMoves) {
                minMoves = currentMoves; // Keep track of the minimum moves
            }
        }
      
        // Return the minimum moves to make all pair sums within the limit
        return minMoves;
    }
};