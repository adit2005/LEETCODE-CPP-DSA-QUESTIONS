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
    // Initialize indices for preorder and postorder arrays
    int pre_idx = 0, post_idx = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // Create a new node with the current value from the preorder array
        TreeNode* root = new TreeNode(preorder[pre_idx++]);

        // If the current root value does not match the current postorder value,
        // this means the left child of the current root is being constructed
        if (root->val != postorder[post_idx]) {
            root->left = constructFromPrePost(preorder, postorder);
        }

        // After constructing the left child, if the root value still doesn't match
        // the current postorder value, it means the right child is being constructed
        if (root->val != postorder[post_idx]) {
            root->right = constructFromPrePost(preorder, postorder);
        }

        // Move to the next postorder index since this node's construction is complete
        post_idx++;

        // Return the constructed root node
        return root;
    }
};
