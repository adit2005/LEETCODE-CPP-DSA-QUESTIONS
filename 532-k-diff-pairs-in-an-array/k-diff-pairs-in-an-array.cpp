class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited; // Set to keep track of visited numbers
        unordered_set<int> foundPairs; // Set to store unique pairs that satisfy the condition
      
        for (int& number : nums) { // Iterate over each number in the given array
            // Check if there's a number in visited set such that the difference between
            // the current number and that number equals k
            if (visited.count(number - k)) {
                // If such a number is found, insert the smaller number of the pair into foundPairs
                foundPairs.insert(number );
            }
          
            // Check if there's a number in visited set such that the difference between
            // that number and the current number equals k
            if (visited.count(number + k)) {
                // If such a number is found, insert the current number into foundPairs
                foundPairs.insert(number+k);
            }
          
            // Mark the current number as visited
            visited.insert(number);
        }
      
        // The result is the number of unique pairs found, which is the size of foundPairs set
        return foundPairs.size();
    }
};
