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
   unordered_set<int> unique_vals;
unordered_map<int, TreeNode*> roots;
vector<TreeNode*> leaves;
void addLeaf(TreeNode* r) {
    if (r != nullptr) {
        unique_vals.insert(r->val);
        if (roots.count(r->val))
            leaves.push_back(r);    
    }
}    
int validNodes(TreeNode* r, int min_left = INT_MIN, int max_right = INT_MAX) {
    if (r == nullptr || r->val <= min_left || r->val >= max_right) 
        return 0;
    return 1 + validNodes(r->left, min_left, r->val) + validNodes(r->right, r->val, max_right);
} 
TreeNode* canMerge(vector<TreeNode*>& trees) {
    for (auto &t : trees)
        roots[t->val] = t;
    for (auto &t : trees) {
        unique_vals.insert(t->val);
        addLeaf(t->left);
        addLeaf(t->right);
    }
    for (auto leaf : leaves) {
        auto it = roots.find(leaf->val);
        if (it == end(roots)) 
            return nullptr;
        leaf->left = it->second->left;
        leaf->right = it->second->right;
        roots.erase(it);
    }
    return roots.size() == 1 && validNodes(begin(roots)->second) == unique_vals.size() ? begin(roots)->second : nullptr;
}
};