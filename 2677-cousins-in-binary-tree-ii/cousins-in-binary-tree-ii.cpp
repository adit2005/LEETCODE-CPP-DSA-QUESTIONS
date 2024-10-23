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
private:
    // Array to store the sum of values at each level
    int levelSums[100000];

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        calculateLevelSum(root, 0);              // First pass to calculate sums
        replaceValueInTreeInternal(root, 0, 0);  // Second pass to update values
        return root;
    }

    // First DFS to calculate the sum of values at each level
    void calculateLevelSum(TreeNode* node, int level) {
        if (node == nullptr) {
            return;
        }

        levelSums[level] += node->val;  // Accumulate sum at the current level
        calculateLevelSum(node->left, level + 1);   // Recur for the left child
        calculateLevelSum(node->right, level + 1);  // Recur for the right child
    }

    // Second DFS to replace each node's value with the sum of its cousins
    void replaceValueInTreeInternal(TreeNode* node, int siblingSum, int level) {
        if (node == nullptr) {
            return;
        }

        // Left child value
        int leftChildVal = node->left == nullptr ? 0 : node->left->val;
        // Right child value
        int rightChildVal = node->right == nullptr ? 0 : node->right->val;

        // For the root and its children, set value to 0
        if (level == 0 || level == 1) {
            node->val = 0;
        } else {
            // Set the node's value to the sum of its cousins
            node->val = levelSums[level] - node->val - siblingSum;
        }

        // Recur for left and right children
        replaceValueInTreeInternal(node->left, rightChildVal, level + 1);
        replaceValueInTreeInternal(node->right, leftChildVal, level + 1);
    }
};