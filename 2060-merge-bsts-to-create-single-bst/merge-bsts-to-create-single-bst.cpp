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
    bool traverse(TreeNode* r, unordered_map<int, TreeNode*> &m, int min_left = INT_MIN, int max_right = INT_MAX) {
    if (r == nullptr) 
        return true;
    if (r->val <= min_left || r->val >= max_right)
        return false;
    if (r->left == r->right) {
        auto it = m.find(r->val);
        if (it != end(m) && r != it->second) {
            r->left = it->second->left;
            r->right = it->second->right;
            m.erase(it);
        }
    }
    return traverse(r->left, m, min_left, r->val) && traverse(r->right, m, r->val, max_right);
}    
TreeNode* canMerge(vector<TreeNode*>& trees) {
    unordered_map<int, TreeNode*> m;
    unordered_map<int, int> cnt;
    for (auto &t : trees) {
        m[t->val] = t;
        ++cnt[t->val];
        ++cnt[t->left ? t->left->val : 0];
        ++cnt[t->right ? t->right->val : 0];
    }
    for (auto &t : trees)
        if (cnt[t->val] == 1)
            return traverse(t, m) && m.size() == 1 ? t : nullptr;
    return nullptr;
}
};