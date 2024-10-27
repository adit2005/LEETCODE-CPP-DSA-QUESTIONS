class Solution {
public:
    int addMinimum(string s) {
        int count = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') { 
                if (i == n - 1) count += 2; // If 'a' is the last character, add 2
                else if (s[i + 1] == 'c') {
                    ++count; // If the next character is 'c', add 1
                    ++i; // Skip the next character
                }
                else if (s[i + 1] == 'b' && (i + 2 != n && s[i + 2] == 'c')) i += 2; // If the next two characters are 'bc', skip them
                else if (s[i + 1] == 'b' && (i + 2 == n || s[i + 2] != 'c')) {
                    ++count; // If the next character is 'b' and the character after that is not 'c', add 1
                    ++i; 
                }
                else count += 2; // If the next character is not 'b' or 'c', i.e another a, add 2
            }
            else if (s[i] == 'b') { 
                if (i == n - 1) { // If b is the last character
                    count+=2;
                }
                else if (s[i + 1] == 'c') {
                    ++count; // If the next character is 'c', we only need to add 'a' in front of bc
                    ++i; 
                }
                else count += 2; 
            }
            else {
                count += 2; // If the character is 'c', add 2 for "ab` before it
            }
        }
        return count;
    }
};