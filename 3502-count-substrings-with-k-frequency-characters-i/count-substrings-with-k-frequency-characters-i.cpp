class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int totalCount = 0;
        vector<int> freq(26, 0); // Frequency array for 'a' to 'z'
        int left = 0; // Sliding window left pointer
        
        for (int right = 0; right < n; ++right) {
            // Increment the frequency of current character
            int idx = s[right] - 'a';
            freq[idx]++;
            
            // Shrink the window from the left as soon as a character reaches frequency >= k
            while (freq[idx] >= k) {
                // All substrings from left to right are valid
                totalCount += (n - right);
                
                // Decrease the frequency of the leftmost character and slide the window
                freq[s[left] - 'a']--;
                left++;
            }
        }
        
        return totalCount;
    }
};
