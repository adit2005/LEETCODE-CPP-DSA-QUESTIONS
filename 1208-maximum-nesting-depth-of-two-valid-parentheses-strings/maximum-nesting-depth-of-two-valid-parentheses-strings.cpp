class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> ans; // To store the assigned group numbers
        int group = 0;   // Initialize group number (0 or 1)

        for (char c : s) {
            if (c == '(') {
                ans.push_back(group);      // Assign current group to opening parenthesis
                group = 1 - group;        // Alternate the group number between 0 and 1
            } else {
                group = 1 - group;        // Alternate the group number for closing parenthesis
                ans.push_back(group);      // Assign the opposite group to closing parenthesis
            }
        }

        return ans; // Return the assigned group numbers
    }
};