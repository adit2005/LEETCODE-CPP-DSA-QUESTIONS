class Solution {
public:
    // Define a constant 'mod' for modulo arithmetic.
    int mod = pow(10, 9) + 7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        // Sort the input vector in ascending order.
        sort(arr.begin(), arr.end());

        // Create an unordered map to store the count of binary trees with roots as values in 'arr'.
        unordered_map<int, long> rootWithCount;
        
        // Initialize the count for the first element in 'arr'.
        rootWithCount[arr[0]] = 1;

        // Iterate through the elements of 'arr' from the second element onward.
        for (int i = 1; i < arr.size(); i++) {
            long count = 1;
            
            // Iterate through the elements in 'rootWithCount'.
            for (auto j : rootWithCount) {
                int rootEle = j.first;
                
                // Check if 'arr[i]' is divisible by 'rootEle' and if 'arr[i] / rootEle' exists in 'rootWithCount'.
                if (arr[i] % rootEle == 0 && rootWithCount.find(arr[i] / rootEle) != rootWithCount.end()) {
                    // Update the count with the product of counts of the two factors.
                    count += rootWithCount[rootEle] * rootWithCount[arr[i] / rootEle];
                }
            }
            
            // Store the count for the current element in 'rootWithCount'.
            rootWithCount[arr[i]] = count;
        }
        
        int noOfTrees = 0;
        
        // Sum up the counts for all root values in 'rootWithCount'.
        for (auto i : rootWithCount) {
            noOfTrees = (noOfTrees + i.second) % mod;
        }
        
        // Return the total count of binary trees.
        return noOfTrees;
    }
};
