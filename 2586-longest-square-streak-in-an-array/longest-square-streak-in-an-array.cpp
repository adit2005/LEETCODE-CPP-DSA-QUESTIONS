class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int longestStreak = 0;

        // Set to store unique numbers from input
        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());

        // Set to mark numbers that have been visited
        unordered_set<int> visited;

        // Iterate through each number in the input array
        for (int startNumber : nums) {
            if (visited.find(startNumber) != visited.end()) {
                // Skip if the number has already been part of a streak
                continue;
            }

            int currentStreak = 0;
            long long current = startNumber;

            // Continue the streak as long as the next square is in the set
            while (uniqueNumbers.find((int)current) != uniqueNumbers.end()) {
                // Mark the current number as visited
                visited.insert(current);

                currentStreak++;

                // Stop if the next square would exceed 10^5
                if (current * current > 1e5) break;

                current *= current;
            }

            // Update the longest streak if necessary
            longestStreak = max(longestStreak, currentStreak);
        }

        // Return -1 if no valid streak found, otherwise return longest streak
        return longestStreak < 2 ? -1 : longestStreak;
    }
};
