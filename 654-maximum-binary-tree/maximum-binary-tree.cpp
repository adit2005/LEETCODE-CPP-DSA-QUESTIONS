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
    TreeNode* build(int lo, int hi, vector<int>& nums) {
        if(lo > hi) return nullptr;

        int maxEl = nums[lo], idx = lo;
        for(int i = lo; i <= hi; i++) {
            if(maxEl < nums[i]) {
                idx = i;
                maxEl = nums[i];
            }
        }

        TreeNode* node = new TreeNode(maxEl);
        node -> left = build(lo, idx - 1, nums);
        node -> right = build(idx + 1, hi, nums);

        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
    }
};