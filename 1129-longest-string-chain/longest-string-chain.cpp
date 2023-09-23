class Solution {
public:
    // Static comparison function used for sorting words by length.
    static bool cmp(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    // Function to find the length of the longest word chain.
    int longestStrChain(vector<string>& words) {
        // Sort the words by length in ascending order using the 'cmp' function.
        sort(words.begin(), words.end(), cmp);

        // Create an unordered map to store the length of the longest chain ending with each word.
        unordered_map<string, int> ump;

        // Initialize the maximum chain length to 0.
        int ans = 0;

        // Iterate through the sorted words.
        for (string w : words) {
            int longest = 0;

            // Iterate through each character position in the current word.
            for (int i = 0; i < w.length(); i++) {
                string sub = w;
                // Remove one character at position 'i' to form a potential predecessor word.
                sub.erase(i, 1);

                // Check if the potential predecessor word exists in the map.
                // Update the longest chain length ending with the current word.
                longest = max(longest, ump[sub] + 1);
            }

            // Store the longest chain length for the current word in the map.
            ump[w] = longest;

            // Update the overall maximum chain length.
            ans = max(ans, longest);
        }

        // Return the maximum chain length found.
        return ans;
    }
};
