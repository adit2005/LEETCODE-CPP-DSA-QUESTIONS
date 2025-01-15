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
    int i = 0; // Tracks the current index in the string `S`.

    // Helper function to recover tree from preorder traversal string
    TreeNode* recoverFromPreorder(string& S, int d) {
        // Step 1: Find the position of the next digit in the string
        int nextDigitPos = S.find_first_of("1234567890", i);

        // Step 2: If the number of '-' before the digit does not match the depth, return NULL
        if (nextDigitPos - i != d)
            return NULL; // Indicates this is not the correct depth, backtrack.

        // Step 3: Find the position of the next '-' (or the end of the string)
        int nextDashPos = S.find("-", nextDigitPos);

        // Step 4: Extract the value of the current node
        int rootValue = stoi(S.substr(nextDigitPos, nextDashPos - nextDigitPos));

        // Step 5: Create the current tree node
        TreeNode* root = new TreeNode(rootValue);

        // Update `i` to point to the next dash position (or the end of the string)
        i = nextDashPos;

        // Step 6: Recursively construct the left and right subtrees
        root->left = recoverFromPreorder(S, d + 1);  // Left subtree at depth d + 1
        root->right = recoverFromPreorder(S, d + 1); // Right subtree at depth d + 1

        return root; // Return the constructed subtree
    }

    // Main function to recover tree from the string
    TreeNode* recoverFromPreorder(string S) {
        return recoverFromPreorder(S, 0); // Start with depth 0
    }
};
