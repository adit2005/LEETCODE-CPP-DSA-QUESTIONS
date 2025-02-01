class Solution {
    // Helper function for backtracking
    void backtrack(string& s, int i, vector<string>& res) {
        // If we have processed all characters, store the current permutation
        if (i == s.size()) {
            res.push_back(s);
            return;
        }

        // Recursive call without changing the current character
        backtrack(s, i + 1, res);

        // If the current character is a letter, toggle its case and recurse
        if (isalpha(s[i])) {
            // Toggle case using bitwise XOR (1 << 5) flips the 6th bit,
            // which converts uppercase to lowercase and vice versa.
            s[i] ^= (1 << 5);
            
            // Recursive call with the toggled case character
            backtrack(s, i + 1, res);

          
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res); // Start backtracking from index 0
        return res;
    }
};
