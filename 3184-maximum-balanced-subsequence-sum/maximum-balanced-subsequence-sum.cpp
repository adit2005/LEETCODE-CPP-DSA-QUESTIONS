#include <vector>
#include <algorithm>
using namespace std;

class BinaryIndexedTree {
private:
    int size_; // Size of the array
    vector<long long> tree_; // The underlying data structure
    const long long INF = 1e18; // An arbitrary large value to represent negative infinity
  
public:
    // Constructor to initialize the binary indexed tree with given size
    BinaryIndexedTree(int size) : size_(size), tree_(size + 1, -INF) { }

    // Updates the tree by setting the value at 'index' to the maximum of its current value and 'value'
    void update(int index, long long value) {
        while (index <= size_) {
            tree_[index] = max(tree_[index], value);
            index += index & -index; // Traverse to parent node
        }
    }

    // Queries the maximum value in the range 1...index
    long long query(int index) {
        long long max_value = -INF;
        while (index > 0) {
            max_value = max(max_value, tree_[index]);
            index -= index & -index; // Traverse to child node
        }
        return max_value;
    }
};

class Solution {
public:
    // Function to compute the maximum balanced subsequence sum
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> processed_nums(n);
      
        // Preprocess the numbers by offsetting with their indices
        for (int i = 0; i < n; ++i) {
            processed_nums[i] = nums[i] - i;
        }
      
        // Sort and deduplicate the processed numbers
        sort(processed_nums.begin(), processed_nums.end());
        processed_nums.erase(unique(processed_nums.begin(), processed_nums.end()), processed_nums.end());
      
        int m = processed_nums.size();
        BinaryIndexedTree tree(m);
        
        // Initialize the global answer to a very small number
        long long ans = -1e18; 
        
        // Process original numbers to update the tree with the maximum value at each point
        for (int i = 0; i < n; ++i) {
            // Find the index in the processed array using lower_bound
            int idx = lower_bound(processed_nums.begin(), processed_nums.end(), nums[i] - i) - processed_nums.begin() + 1;
            
            // Query the tree for the maximum sum up to the current index
            long long value = tree.query(idx) + nums[i];
            
            // Update the global maximum balanced subsequence sum
            ans = max(ans, value);
            
            // Update the tree with the new value at the current index
            tree.update(idx, value);
        }
      
        // Return the maximum balanced subsequence sum
        return ans;
    }
};
