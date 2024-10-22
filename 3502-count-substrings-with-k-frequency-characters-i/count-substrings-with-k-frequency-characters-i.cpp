class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int totalCount = 0;

        // Sliding window approach
        for (int left = 0; left < n; ++left) {
            vector<int> freq(26, 0); // Frequency array for 'a' to 'z'
            int valid = 0; // Tracks if we have any character with frequency >= k

            for (int right = left; right < n; ++right) {
                // Increment frequency of current character
                int idx = s[right] - 'a';
                freq[idx]++;

                // Check if we just reached the frequency k for this character
                if (freq[idx] == k) {
                    valid++;
                }

                // Count the substring if there is at least one character with frequency >= k
                if (valid > 0) {
                    totalCount++;
                }
            }
        }

        return totalCount;
    }
};
