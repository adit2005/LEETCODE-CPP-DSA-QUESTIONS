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
    // Helper function to calculate the size of a perfect binary subtree
    int findPerfectSubtreeSize(TreeNode* root, vector<int>& subtreeSizes) {
        // Base case: null node
        if (!root) return 0;

        // Recursively calculate the size of left and right subtrees
        int leftSize = findPerfectSubtreeSize(root->left, subtreeSizes);
        int rightSize = findPerfectSubtreeSize(root->right, subtreeSizes);

        // If both subtrees are perfect and of the same size
        if (leftSize == rightSize && leftSize >= 0  ) {
            int subtreeSize = 1 + leftSize + rightSize; // Current node + left + right
            subtreeSizes.push_back(subtreeSize);       // Add to the list of sizes
            return subtreeSize;                        // Return size of the subtree
        }

        // If not perfect, return 0 (not a perfect subtree)
        return -1;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> subtreeSizes;

        // Find all perfect subtree sizes
        findPerfectSubtreeSize(root, subtreeSizes);

        // Sort the valid subtree sizes in descending order
        sort(subtreeSizes.rbegin(), subtreeSizes.rend());

        // Check if k is within range
        if (k > subtreeSizes.size()) return -1;

        // Get the k-th largest size
        int result = subtreeSizes[k - 1];

        
        return result ;
    }
};
