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
    // Function to check if two trees are flip equivalent
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, they are equivalent
        if (!root1 && !root2)
            return true;
        
        // If one of the nodes is null or the values are not equal, they are not equivalent
        if (!root1 || !root2 || root1->val != root2->val)
            return false;
        
        // Recursively check the children of root1 and root2
        // left1 and right1 are for checking without flipping
        // left2 and right2 are for checking with flipping
        bool left1, right1, left2, right2;

        // Check if left child of root1 is equivalent to left child of root2
        left1 = flipEquiv(root1->left, root2->left);
        
        // Check if right child of root1 is equivalent to right child of root2
        right1 = flipEquiv(root1->right, root2->right);
        
        // Check if left child of root1 is equivalent to right child of root2 (flip case)
        left2 = flipEquiv(root1->left, root2->right);
        
        // Check if right child of root1 is equivalent to left child of root2 (flip case)
        right2 = flipEquiv(root1->right, root2->left);

        // The two trees are flip equivalent if either:
        // 1. Both corresponding children are equivalent without flipping
        // 2. Both corresponding children are equivalent with flipping
        return ((left1 && right1) || (left2 && right2));
    }
};
