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
    TreeNode* bstToGst(TreeNode* root) {
        // Initialize a local variable nodeSum.
        int nodeSum = 0;
        bstToGstHelper(root, nodeSum);
        return root;
    }

private:
    void bstToGstHelper(TreeNode* root, int& nodeSum) {
        // If root is null, make no changes.
        if (!root) {
            return;
        }

        bstToGstHelper(root->right, nodeSum);
        nodeSum += root->val;
        // Update the value of root.
        root->val = nodeSum;
        bstToGstHelper(root->left, nodeSum);
    }
};