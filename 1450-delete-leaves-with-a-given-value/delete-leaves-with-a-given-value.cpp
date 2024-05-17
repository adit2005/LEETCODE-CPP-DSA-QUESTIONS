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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        }

        // 1. Visit the left children
        root->left = removeLeafNodes(root->left, target); 

        // 2. Visit the right children
        root->right = removeLeafNodes(root->right, target); 

        // 3. check if the current node is a leaf node and its value equals target. 
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            // Delete the node by returning a nullptr to the parent, effectively disconnecting it.
            return nullptr;
        }
        // keep it untouched otherwise
        return root;
    }
};