class Solution {
public:
    static const int MOD_VALUE = 1e9 + 7; // Modulo value to prevent overflow
    int dpTable[3][1001][2001]; // DP table for storing results: [lastPick][index][currentScore]

    // Recursive function to calculate valid sequences
    long long calculateSequences(string& sequence, int lastPick, int index, long long currentScore) {
        // Base case: If we've reached the end of the sequence
        if (index >= sequence.size()) {
            return currentScore > 0 ? 1 : 0; // Return 1 if score is positive, else 0
        }
        
        // Check if the result for this state is already computed
        if (dpTable[lastPick][index][currentScore + 1000] != -1)
            return dpTable[lastPick][index][currentScore + 1000];

        // Initialize paths for each choice
        long long fPaths = 0, wPaths = 0, ePaths = 0;
        char currentChar = sequence[index]; // Get the current character in the sequence

        // Handle transitions based on the current character
        if (currentChar == 'F') {
            // If the last pick was not 'F', we can pick 'F' again
            fPaths = (lastPick != 0) ? calculateSequences(sequence, 0, index + 1, currentScore) % MOD_VALUE : 0;
            // If the last pick was not 'W', we can pick 'W' and increase score
            wPaths = (lastPick != 1) ? calculateSequences(sequence, 1, index + 1, currentScore + 1) % MOD_VALUE : 0;
            // If the last pick was not 'E', we can pick 'E' and decrease score
            ePaths = (lastPick != 2) ? calculateSequences(sequence, 2, index + 1, currentScore - 1) % MOD_VALUE : 0;
        } else if (currentChar == 'W') {
            // If the last pick was not 'F', we can pick 'F' and decrease score
            fPaths = (lastPick != 0) ? calculateSequences(sequence, 0, index + 1, currentScore - 1) % MOD_VALUE : 0;
            // If the last pick was not 'W', we can pick 'W' and keep the score
            wPaths = (lastPick != 1) ? calculateSequences(sequence, 1, index + 1, currentScore) % MOD_VALUE : 0;
            // If the last pick was not 'E', we can pick 'E' and increase score
            ePaths = (lastPick != 2) ? calculateSequences(sequence, 2, index + 1, currentScore + 1) % MOD_VALUE : 0;
        } else { // currentChar == 'E'
            // If the last pick was not 'F', we can pick 'F' and increase score
            fPaths = (lastPick != 0) ? calculateSequences(sequence, 0, index + 1, currentScore + 1) % MOD_VALUE : 0;
            // If the last pick was not 'W', we can pick 'W' and decrease score
            wPaths = (lastPick != 1) ? calculateSequences(sequence, 1, index + 1, currentScore - 1) % MOD_VALUE : 0;
            // If the last pick was not 'E', we can pick 'E' and keep the score
            ePaths = (lastPick != 2) ? calculateSequences(sequence, 2, index + 1, currentScore) % MOD_VALUE : 0;
        }

        // Store the result in dpTable and return it
        return dpTable[lastPick][index][currentScore + 1000] = (fPaths + wPaths + ePaths) % MOD_VALUE;
    }

    // Function to count total winning sequences
    int countWinningSequences(string s) {
        memset(dpTable, -1, sizeof(dpTable)); // Initialize dpTable with -1
        long long totalWinningSequences = 0; // Initialize total count of winning sequences

        // Iterate over possible last picks (0: 'F', 1: 'W', 2: 'E')
        for (int lastPick = 0; lastPick < 3; ++lastPick) {
            totalWinningSequences += calculateSequences(s, lastPick, 0, 0); // Accumulate winning sequences
            totalWinningSequences %= MOD_VALUE; // Ensure the total stays within bounds
        }

        // Return the total count adjusted by the modular inverse of 2
        return (totalWinningSequences * 500000004) % MOD_VALUE;
    }
};
