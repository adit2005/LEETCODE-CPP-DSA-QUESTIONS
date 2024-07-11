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
    vector<int> A;

    // Construct the array.
    for (ListNode* curr = head; curr; curr = curr->next)
      A.push_back(curr->val);

    return helper(A, 0, A.size() - 1);
  }

 private:
  TreeNode* helper(const vector<int>& A, int l, int r) {
    if (l > r)
      return nullptr;

    const int m = (l + r) / 2;
    TreeNode* root = new TreeNode(A[m]);
    root->left = helper(A, l, m - 1);
    root->right = helper(A, m + 1, r);
    return root;
  }
};