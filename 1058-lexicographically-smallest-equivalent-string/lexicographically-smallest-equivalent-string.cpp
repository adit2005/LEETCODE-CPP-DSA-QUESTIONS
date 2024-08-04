class Solution {
public:
    // Helper function to perform DFS and find the smallest character in the connected component
    char dfs(unordered_map<char, vector<char>>& mapping, char input, unordered_set<char>& visited) {
        if (visited.count(input) > 0) {
            return input;  // Return if the character has already been visited
        }
        visited.insert(input);  // Mark the character as visited
        char ret = input;  // Initialize the smallest character with the input character
        for (const auto ch : mapping[input]) {
            ret = min(ret, dfs(mapping, ch, visited));  // Recursively find the smallest character
        }
        return ret;
    }

public:
    string smallestEquivalentString(string A, string B, string S) {
        unordered_map<char, vector<char>> mapping;  // Adjacency list for character mappings
        // Build the graph based on pairs in A and B
        for (int i = 0; i < A.size(); ++i) {
            mapping[A[i]].push_back(B[i]);
            mapping[B[i]].push_back(A[i]);
        }
        string ret;  // Resultant string
        unordered_map<char, char> memo;  // Memoization for characters to their smallest equivalent
        // Process each character in S
        for (const auto s : S) {
            if (memo.count(s) > 0) {
                ret += memo[s];  // Use memoized result if available
                continue;
            }
            unordered_set<char> visited;  // Set to keep track of visited characters
            const auto min_char = dfs(mapping, s, visited);  // Find the smallest equivalent character
            // Memoize the smallest character for all visited characters
            for (const auto ch : visited) {
                memo[ch] = min_char;
            }
            ret += min_char;  // Append the smallest character to the result
        }
        return ret;  // Return the resultant string
    }
};
