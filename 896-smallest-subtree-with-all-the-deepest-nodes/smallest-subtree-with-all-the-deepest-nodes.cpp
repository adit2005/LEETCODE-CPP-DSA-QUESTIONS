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

 //idea is find all nodes in last level & then find the least common ancestor for extreme left node & extreme right node.
class Solution {
public:
    TreeNode* lca( TreeNode* root, TreeNode* p, TreeNode* q ) {
        if ( !root || root == p || root == q ) return root;
        TreeNode *left = lca( root->left, p, q );
        TreeNode *right = lca (root->right, p, q );

        return !left? right: !right? left: root;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if ( !root || !root->left && !root->right ) return root;
        TreeNode *leftMost = NULL;
        TreeNode *rightMost = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ) {
            int levelSize = q.size();
            for(int level = 0; level < levelSize; level++ ) {
                TreeNode* node = q.front(); q.pop();
                if ( level == 0 ) leftMost = node;
                if ( level == levelSize - 1 ) rightMost = node;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
        }
        return lca( root, leftMost, rightMost );
    }
};