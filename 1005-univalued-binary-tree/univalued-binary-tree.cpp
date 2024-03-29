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
    bool fun(TreeNode* root, int v){
        if(root==0)return true;
        else if(root->val!= v) return false;
        return fun(root->left,v)&&fun(root->right,v);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(root==0)return true;
        return fun(root,root->val);
    }
};