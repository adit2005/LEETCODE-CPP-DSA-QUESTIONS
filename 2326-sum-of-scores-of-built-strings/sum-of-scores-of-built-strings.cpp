class Solution {
public:
    // Function to compute the LPS (Longest Prefix Suffix) array for the string `s`
    vector<int> lps(string& s) {
        vector<int> lps(s.size()); // LPS array to store the length of the longest prefix-suffix
        for (int i = 1, j = 0; i < s.size(); ++i) {
            // If there's a mismatch between the current character and the prefix
            while (j && s[i] != s[j])
                j = max(0, lps[j - 1]); // Backtrack to the previous valid LPS value
            
            // If there's a match, extend the prefix-suffix length
            j += (s[i] == s[j]);
            lps[i] = j; // Update the LPS value for the current position
        }
        return lps;
    }

    // Function to compute the sum of scores of all prefixes of the string `s`
    long long sumScores(string s) {
        vector<int> cnt; // To store the cumulative sum of valid LPS values
        for (int j : lps(s)) {
            // If `j` (LPS value) is 0, the score is 0; otherwise, extend the previous score
            cnt.push_back(j == 0 ? 0 : cnt[j - 1] + 1);
        }
        
        // The total score is the sum of `cnt` values plus the size of the string
        // (the length of the entire string contributes to the score of itself as a prefix)
        return accumulate(begin(cnt), end(cnt), 0LL) + s.size();
    }
};
