class Solution {
public:
    int balancedString(string s) {
        int length = s.size();
        unordered_map<char, int> charCount;
        int left = 0;
        int ans = length;
        int targetCount = length / 4;

        // Count the occurrences of each character
        for (char c : s) {
            charCount[c]++;
        }

        for (int right = 0; right < length; right++) {
            // Decrement the count of the character at the current index
            charCount[s[right]]--;

            // Shrink the window by moving the left pointer
            while (left < length && charCount['Q'] <= targetCount && charCount['W'] <= targetCount &&
                   charCount['E'] <= targetCount && charCount['R'] <= targetCount) {
                // Update the answer
                ans = min(ans, right - left + 1);
                // Increment the count of the character at the left pointer
                charCount[s[left]]++;
                // Move the left pointer
                left++;
            }
        }

        return ans;
    }
};
