class Solution {
public:
    // Function to compute the Longest Prefix Suffix (LPS) array for the given string 'word'.
    // The LPS array is used to store the length of the longest prefix of the string which
    // is also a suffix for every possible length of the string from 0 to the full length.
    vector<int> lps(string& word) {
        // Initialize the LPS array with 0s, having the same length as the word.
        vector<int> lp(word.length(), 0);
      
        int index = 0;

        // Start iterating from the second character of the string (index 1).
        for(int i = 1; i < word.length();) {
            // If the current character matches the character at 'index', it means we have found
            // a longer prefix that is also a suffix. We increment 'index' and set 'lp[i]'.
            if(word[i] == word[index]) {
                index++;
                lp[i] = index;
                i++;
            } 
            // If the characters do not match and 'index' is not zero, we set 'index' to the value of 'lp[index-1]'
            // which is the length of the next longest prefix suffix that we need to check.
            else {
                if(index != 0)
                    index = lp[index-1];
                // If 'index' is zero, we can't find a matching prefix suffix, so we just move to the next character.
                else
                    i++;
            }
        }
        
        // Return the computed LPS array.
        return lp;
    }
    
    // Function to find the longest prefix of the string 's' which is also a suffix.
    string longestPrefix(string s) {
        // Compute the LPS array for the given string.
        vector<int> lp = lps(s);
        
        // The last value in the LPS array gives the length of the longest prefix which is also a suffix.
        // We return the substring of 's' from the start up to this length.
        return s.substr(0, lp.back());
    }
};
