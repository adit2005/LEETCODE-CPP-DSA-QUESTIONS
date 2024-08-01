class Solution {
public:
    // Number of letters in the alphabet
    int alphabet = 26;

    // Function to check if 'temp' appears as a subsequence in 's' at least 'k' times
    bool find(string &s, string &temp, int k) {
        int j = 0; // Pointer for 'temp'
        int n = s.length();
        int count = 0; // Counter for the number of times 'temp' appears in 's'

        for (int i = 0; i < n; i++) {
            if (s[i] == temp[j]) {
                j++;
                // If we have matched the entire 'temp', increment the counter and reset the pointer
                if (j == temp.size()) {
                    count++;
                    j = 0;
                }
                // If 'temp' has appeared at least 'k' times, return true
                if (count == k) {
                    return true;
                }
            }
        }
        // If 'temp' does not appear at least 'k' times, return false
        return false;
    }

    // Main function to find the longest subsequence repeated 'k' times
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        queue<string> q;
        q.push(""); // Start with an empty string
        string ans = ""; // Variable to store the longest subsequence found

        // Breadth-First Search (BFS) using a queue
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // Try appending each character from 'a' to 'z' to the current string 'curr'
            for (int i = 0; i < alphabet; i++) {
                string temp = curr + char('a' + i);
                // If the new string 'temp' appears at least 'k' times in 's'
                if (find(s, temp, k)) {
                    ans = temp; // Update the answer with the new valid subsequence
                    q.push(temp); // Push the new string into the queue to explore further
                }
            }
        }
        return ans; // Return the longest valid subsequence found
    }
};
