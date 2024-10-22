class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string current = ""; // This keeps track of the current string on the screen

        // Iterate over each character in the target string
        for (char ch : target) {
            // Step 1: Append 'a' using Key 1
            current += 'a';
            result.push_back(current); // Add this string to the result

            // Step 2: Change the last character to match the target character using Key 2
            while (current.back() != ch) {
                current.back() = (current.back() - 'a' + 1) % 26 + 'a'; // Increment character
                result.push_back(current); // Add each intermediate step to the result
            }
        }
        
        return result;
    }
};
