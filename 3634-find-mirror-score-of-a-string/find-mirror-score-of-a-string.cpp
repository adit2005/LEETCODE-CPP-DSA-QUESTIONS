class Solution {
public:
    long long calculateScore(string s) {
        // Step 1: Create the mirror map
        unordered_map<char, char> mirror_map;
        for (char c = 'a'; c <= 'z'; c++) {
            mirror_map[c] = 'z' - (c - 'a');
        }
        
        // Step 2: Data structure to store previous indices
        map<char, set<int>> prev_indices; // Automatically sorted indices
        long long score = 0;

        // Step 3: Traverse the string
        for (int i = 0; i < s.length(); i++) {
            char current_char = s[i];
            char mirror_char = mirror_map[current_char];

            // Step 4: Check for the closest unmarked mirror index
            if (prev_indices.count(mirror_char) && !prev_indices[mirror_char].empty()) {
                // Find the largest valid index smaller than i
                auto it = prev_indices[mirror_char].end();
                it--; // Get the largest index in the set
                int j = *it;

                // Add the score and remove the used index
                score += (i - j);
                prev_indices[mirror_char].erase(it); // Remove the used index
            } else {
                // Store the current index in sorted order
                prev_indices[current_char].insert(i);
            }
        }

        // Step 5: Return the total score
        return score;
    }
};
