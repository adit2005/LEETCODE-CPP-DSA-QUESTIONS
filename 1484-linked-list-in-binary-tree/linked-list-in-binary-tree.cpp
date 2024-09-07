/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        // Initialize a stack for DFS on the tree
        stack<TreeNode*> nodes;
        nodes.push(root);

        // Perform DFS
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();

            // Check if the current node's path matches the linked list
            if (isMatch(node, head)) {
                return true;
            }

            // Push left and right children onto the stack
            if (node->left) {
                nodes.push(node->left);
            }
            if (node->right) {
                nodes.push(node->right);
            }
        }

        return false;
    }

private:
    bool isMatch(TreeNode* node, ListNode* lst) {
        stack<pair<TreeNode*, ListNode*>> s;
        s.push({node, lst});

        while (!s.empty()) {
            auto [currentNode, currentList] = s.top();
            s.pop();

            while (currentNode && currentList) {
                if (currentNode->val != currentList->val) {
                    break;
                }
                currentList = currentList->next;

                if (currentList) {
                    if (currentNode->left) {
                        s.push({currentNode->left, currentList});
                    }
                    if (currentNode->right) {
                        s.push({currentNode->right, currentList});
                    }
                    break;
                }
            }

            if (!currentList) {
                return true;
            }
        }

        return false;
    }
};