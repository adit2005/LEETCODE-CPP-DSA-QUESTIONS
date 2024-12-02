/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans;

    // Returns the length of the longest path (number of nodes) under the root
    // that have the value same as the root. The path could either be
    // on the left or right child of the root. The length includes the root as well.
    int solve(TreeNode* root, int parent) {
        if (root == NULL) {
            return 0;
        }

        int left = solve(root->left, root->val);
        int right = solve(root->right, root->val);
        
        //The longest univalue path will cover nodes on both sides of the root.
        ans = max(ans, left + right);

        // The number of nodes will be zero if the root value isn't equal to the root.
        // Otherwise return the max of left and right nodes plus one for the root itself.
        return root->val == parent ? max(left, right) + 1 : 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        // Use -1 for the parent value for the tree root node.
        solve(root, -1);
        
        return ans;
    }
};