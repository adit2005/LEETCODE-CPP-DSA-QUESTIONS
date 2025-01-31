/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    string tree2str(TreeNode* root) {
        // Check if the tree is empty
        if (!root)
            return "";

        // Initialize an empty result string
        string res;
        // Initialize a stack for iterative traversal
        stack<TreeNode*> st;
        // Use a set to track visited nodes
        unordered_set<TreeNode*> visited;
        // Push the root onto the stack
        st.push(root);

        // Iterate through the tree using a stack
        while (!st.empty()) {
            // Get the current node from the top of the stack
            TreeNode* cur = st.top();

            // If the current node is already visited, pop it from the stack and
            // close the parenthesis
            if (visited.count(cur)) {
                st.pop();
                res += ")";
            } else {
                // If the current node is not visited, mark it as visited and
                // add its value to the result
                visited.insert(cur);
                res += "(" + to_string(cur->val);

                // If the current node has no left child and a right child, add
                // an empty pair of parentheses
                if (!cur->left && cur->right) {
                    res += "()";
                }

                // Add the right child to the stack if it exists
                if (cur->right)
                    st.push(cur->right);

                // Add the left child to the stack if it exists
                if (cur->left)
                    st.push(cur->left);
            }
        }

        // Return the result string with leading '(' and trailing ')' removed
        return res.substr(1, res.length() - 2);
    }
};