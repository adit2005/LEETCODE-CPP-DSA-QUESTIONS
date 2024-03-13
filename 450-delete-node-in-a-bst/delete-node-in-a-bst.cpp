#include <stack>

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        
        TreeNode* cur = root;
        TreeNode* parent = NULL;
        bool isLeftChild = false;
        
        // Search for the node to delete
        while (cur != NULL && cur->val != key) {
            parent = cur;
            if (key < cur->val) {
                cur = cur->left;
                isLeftChild = true;
            } else {
                cur = cur->right;
                isLeftChild = false;
            }
        }
        
        // Node not found
        if (cur == NULL)
            return root;
        
        // Case 1: Node to delete has no children
        if (cur->left == NULL && cur->right == NULL) {
            if (parent == NULL)
                return NULL;
            if (isLeftChild)
                parent->left = NULL;
            else
                parent->right = NULL;
            delete cur;
        } 
        // Case 2: Node to delete has one child
        else if (cur->left == NULL || cur->right == NULL) {
            TreeNode* child = (cur->left != NULL) ? cur->left : cur->right;
            if (parent == NULL)
                return child;
            if (isLeftChild)
                parent->left = child;
            else
                parent->right = child;
            delete cur;
        } 
        // Case 3: Node to delete has two children
        else {
            TreeNode* largestLeft = cur->left;
            TreeNode* largestLeftParent = cur;
            while (largestLeft->right != NULL) {
                largestLeftParent = largestLeft;
                largestLeft = largestLeft->right;
            }
            // Replace value of the node to be deleted with the value of its largest left child
            cur->val = largestLeft->val;
            // Delete the largest left child node (which has either no children or only a left child)
            if (largestLeftParent->left == largestLeft)
                largestLeftParent->left = largestLeft->left;
            else
                largestLeftParent->right = largestLeft->left;
            delete largestLeft;
        }
        
        return root;
    }
};
