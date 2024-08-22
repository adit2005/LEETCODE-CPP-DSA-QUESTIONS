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
    // Recursive helper function to build the tree
    TreeNode* solve(vector<int> &preorder, unordered_map<int,int> &mp,
                    int pre_start, int pre_end, int post_start, int post_end) {
        // Base case: if the current subtree is empty
        if (pre_start > pre_end || post_start > post_end)
            return NULL;
        
        // Create the root node with the current start of the preorder array
        TreeNode *root = new TreeNode(preorder[pre_start]);

        // If there's only one node in this subtree, return the root
        if (pre_start == pre_end)
            return root;
        
        // Find the position of the left child (preorder[pre_start + 1]) in the postorder array
        int temp = mp[preorder[pre_start + 1]];
        
        // Calculate the length of the left subtree
        int len = temp - post_start + 1;
        
        // Recursively construct the left subtree
        root->left = solve(preorder, mp, pre_start + 1, pre_start + len,
                           post_start, temp);
        
        // Recursively construct the right subtree
        root->right = solve(preorder, mp, pre_start + len + 1, pre_end,
                            temp + 1, post_end - 1);
        
        // Return the constructed root node
        return root;    
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // Create a map to store the indices of the postorder values
        unordered_map<int,int> mp;
        int n = postorder.size();
        
        // Fill the map with value-index pairs from the postorder array
        for (int i = 0; i < n; i++) {
            mp[postorder[i]] = i;
        }
        
        // Call the recursive helper function to build the tree
        return solve(preorder, mp, 0, n - 1, 0, n - 1);
    }
};
