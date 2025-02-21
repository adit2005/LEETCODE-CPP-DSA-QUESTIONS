class FindElements {
    TreeNode* root; 

    bool dfs(TreeNode* node, int target) {
        if (!node) return false;
        if (node->val == target) return true;
        if (node->val > target) return false; // Stop searching if value exceeds target
        return dfs(node->left, target) || dfs(node->right, target);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        recoverTree(root);
    }

    void recoverTree(TreeNode* node) {
        if (!node) return;
        if (node->left) {
            node->left->val = 2 * node->val + 1;
            recoverTree(node->left);
        }
        if (node->right) {
            node->right->val = 2 * node->val + 2;
            recoverTree(node->right);
        }
    }

    bool find(int target) {
        return dfs(root, target);
    }
};
