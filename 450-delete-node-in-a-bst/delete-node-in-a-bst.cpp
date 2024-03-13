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
            TreeNode* successor = cur->right;
            TreeNode* successorParent = cur;
            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }
            // Replace value of the node to be deleted with the value of its successor
            cur->val = successor->val;
            // Delete the successor node (which has either no children or only a right child)
            if (successorParent->left == successor)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;
            delete successor;
        }
        
        return root;
    }
};
