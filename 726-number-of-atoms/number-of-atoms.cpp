class Solution {
public:
    string countOfAtoms(string exp) {
        // Create a map to store the count of each atom encountered
        map<string, int> atoms;
        // Initialize the answer string
        string ans;
        // Initialize variables for counting and multiplying
        int cnt = 0, mult = 1;
        // Create a stack to keep track of multiplier for parenthesis
        stack<int> st;

        // Traverse the expression string backwards
        for (int i = size(exp) - 1; i >= 0; i--) {
            // If the character is a lowercase letter, it's part of an atom name
            if (isalpha(exp[i]) and islower(exp[i])) {
                int len = 2;
                i--;
                // Keep moving backwards to get the complete atom name
                // while (i >= 0 and islower(exp[i])) {
                //     i--;
                //     len++;
                // }
                // Extract the atom name from the substring
                string atom = exp.substr(i, len);
                // Update the count of the atom in the map
                atoms[atom] += max(cnt, 1) * mult;
                // Reset the count
                cnt = 0;
            } 
            // If the character is an uppercase letter, it's either the start of an atom or a single-letter atom
            else if (isalpha(exp[i]) and isupper(exp[i])) {
                string atom(1, exp[i]);
                // Update the count of the atom in the map
                atoms[atom] += max(cnt, 1) * mult;
                // Reset the count
                cnt = 0;
            } 
            // If the character is a digit, it represents the count of the current atom
            else if (isdigit(exp[i])) {
                cnt = exp[i] - '0';
                int p = 10;
                // Keep moving backwards to get multi-digit counts
                while (i - 1 >= 0 and isdigit(exp[i - 1])) {
                    cnt += p * (exp[--i] - '0');
                    p *= 10;
                }
            } 
            // If the character is '(', push the current multiplier onto the stack and update the multiplier
            else if (exp[i] == ')') {
                st.push(mult);
                mult *= max(cnt, 1);
                // Reset the count
                cnt = 0;
            } 
            // If the character is ')', pop the multiplier from the stack
            else {
                mult = st.top();
                st.pop();
            }
        }

        // Construct the answer string from the map
        for (auto [atom, count]: atoms) {
            ans += atom;
            // Append the count if it's greater than 1
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};
