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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Step 1: Organize data
        unordered_map<int, vector<pair<int, bool>>> parentToChildren;
        unordered_set<int> allNodes;
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            parentToChildren[parent].push_back({child, isLeft});
            allNodes.insert(parent);
            allNodes.insert(child);
            children.insert(child);
        }

        // Step 2: Find the root
        int rootVal = 0;
        for (int node : allNodes) {
            if (!children.contains(node)) {
                rootVal = node;
                break;
            }
        }

        // Step 3 & 4: Build the tree using DFS
        return dfs(parentToChildren, rootVal);
    }

private:
    TreeNode* dfs(unordered_map<int, vector<pair<int, bool>>>& parentToChildren,
                  int val) {
        // Create new TreeNode for current value
        TreeNode* node = new TreeNode(val);

        // If current node has children, recursively build them
        if (parentToChildren.find(val) != parentToChildren.end()) {
            for (auto& child_info : parentToChildren[val]) {
                int child = child_info.first;
                bool isLeft = child_info.second;

                // Attach child node based on isLeft flag
                if (isLeft) {
                    node->left = dfs(parentToChildren, child);
                } else {
                    node->right = dfs(parentToChildren, child);
                }
            }
        }

        return node;
    }
};
