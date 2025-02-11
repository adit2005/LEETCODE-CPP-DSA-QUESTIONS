class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int strLength = s.length();
        int partLength = part.length();

        // Iterate through each character in the string
        for (int index = 0; index < strLength; index++) {
            // Push current character to stack
            stk.push(s[index]);

            // If stack size is greater than or equal to the part length, check
            // for match
            if (stk.size() >= partLength && checkMatch(stk, part, partLength)) {
                // Pop the characters matching 'part' from the stack
                for (int j = 0; j < partLength; j++) {
                    stk.pop();
                }
            }
        }

        // Convert stack to string with correct order
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }

private:
    // Helper function to check if the top of the stack matches the 'part'
    bool checkMatch(stack<char>& stk, string& part, int partLength) {
        stack<char> temp = stk;

        // Iterate through part from right to left
        for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) {
            // If current stack top doesn't match expected character
            if (temp.top() != part[partIndex]) {
                return false;
            }
            temp.pop();
        }
        return true;
    }
};