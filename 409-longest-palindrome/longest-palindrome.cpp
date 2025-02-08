class Solution {
public:
    int longestPalindrome(string s) {
        int oddFreqCharsCount = 0;
        unordered_map<char, int> frequencyMap;

        // Loop over the string
        for (char c : s) {
            // Update count of current character
            frequencyMap[c]++;

            // If the current freq of the character is odd,
            // increment oddCount
            if ((frequencyMap[c] % 2) == 1) {
                oddFreqCharsCount++;
            } else {
                oddFreqCharsCount--;
            }
        }

        // If there are characters with odd frequencies, we are
        // guaranteed to have at least one letter left unmatched,
        // which can make the center of an odd length palindrome.
        if (oddFreqCharsCount > 0) {
            return s.length() - oddFreqCharsCount + 1;
        } else {
            return s.length();
        }
    }
};