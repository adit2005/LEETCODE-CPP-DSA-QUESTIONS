class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> matchingWords;

        // Iterate through each word in the input list.
        for (int currentWordIndex = 0; currentWordIndex < words.size(); currentWordIndex++) {
            // Compare the current word with all other words.
            for (int otherWordIndex = 0; otherWordIndex < words.size(); otherWordIndex++) {
                if (currentWordIndex == otherWordIndex)
                    continue; // Skip comparing the word with itself.

                // Use std::string::find to check if the current word is a substring of another word.
                if (words[otherWordIndex].find(words[currentWordIndex]) != std::string::npos) {
                    // Add it to the result list if true.
                    matchingWords.push_back(words[currentWordIndex]);
                    break; // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }
};
