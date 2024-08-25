class Solution {
public:
    // Helper function to calculate the maximum length of consecutive characters 'c'
    // after flipping at most 'k' characters in the string 'list' of length 'n'.
    int maxW(string list, int n, char c, int k) {
        int ans = 0;  // Stores the maximum length of consecutive 'c' characters
        int flip = 0; // Counts the number of flips made (i.e., non-'c' characters within the window)
        int l = 0;    // Left pointer for the sliding window

        // Iterate over the string with the right pointer 'r'
        for (int r = 0; r < n; r++) {
            // If the current character is not 'c', increment the flip counter
            flip += (list[r] != c);

            // If the number of flips exceeds 'k', shrink the window from the left
            if (flip > k) {
                // Move the left pointer 'l' to the right until we remove a non-'c' character
                while (list[l] == c)
                    l++;
                l++;      // Skip the non-'c' character
                flip--;   // Decrement the flip counter as we've excluded one flip from the window
            }

            // Update the maximum length of consecutive 'c' characters in the current window
            ans = max(ans, r - l + 1);
        }
        return ans; // Return the maximum length found
    }

    // Main function to determine the maximum consecutive 'T' or 'F' characters
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(); // Get the length of the string

        // Return the maximum of two scenarios:
        // 1. Treating 'T' as the target character and flipping 'F's
        // 2. Treating 'F' as the target character and flipping 'T's
        return max(maxW(answerKey, n, 'T', k), maxW(answerKey, n, 'F', k));
    }
};
