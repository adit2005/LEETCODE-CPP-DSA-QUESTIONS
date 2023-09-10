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
 // use of lower bound and upper bound concept//
class Solution {
public:
    TreeNode* buildBST(vector<int>& preorder,int& index,int lowerBound,int upperBound){
        if(index>=preorder.size()) return NULL;
        if(preorder[index]<lowerBound || preorder[index]>upperBound) return NULL;
        
        TreeNode* node=new TreeNode(preorder[index++]);
        node->left=buildBST(preorder,index,lowerBound,node->val);
        node->right=buildBST(preorder,index,node->val,upperBound);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return buildBST(preorder,index,INT_MIN,INT_MAX);
    }
};