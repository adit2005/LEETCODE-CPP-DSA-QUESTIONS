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
  TreeNode* sortedListToBST(ListNode* head) {
    this->head = head;
    return helper(0, getLength(head) - 1);
  }

 private:
  ListNode* head;

  TreeNode* helper(int l, int r) {
    if (l > r)
      return nullptr;

    const int m = (l + r) / 2;

    // Simulate inorder traversal: recursively form the left half.
    TreeNode* left = helper(l, m - 1);

    // Once the left half is traversed, process the current node.
    TreeNode* root = new TreeNode(head->val);
    root->left = left;

    // Maintain the invariance.
    head = head->next;

    // Simulate inorder traversal: recursively form the right half.
    root->right = helper(m + 1, r);
    return root;
  }

  int getLength(ListNode* head) {
    int length = 0;
    for (ListNode* curr = head; curr; curr = curr->next)
      ++length;
    return length;
  }
};