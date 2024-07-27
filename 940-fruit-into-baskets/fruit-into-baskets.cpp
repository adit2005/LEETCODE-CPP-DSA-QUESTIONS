class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // If the fruits array is empty, return 0 as no fruits can be collected.
        if (fruits.empty())
            return 0;
        
        // Initialize variables to keep track of the maximum sequence length.
        int maxSequence = 0;

        // Variables to store the types of fruits in the two baskets.
        int firstType = -1, lastType = -1;

        // Variables to store the starting indices of the sequences of these fruit types.
        int firstIndex = 0, lastIndex = 0;

        // Iterate through each fruit in the fruits array.
        for (int i = 0; i < fruits.size(); ++i) {
            // If the current fruit type is different from the last recorded fruit type.
            if (lastType != fruits[i]) {
                // If the current fruit matches the first type, swap first and last types.
                if (firstType == fruits[i]) {
                    swap(firstType, lastType);
                } 
                else {
                    // Otherwise, update the maximum sequence length.
                    maxSequence = max(maxSequence, i - firstIndex);

                    // Update first type and its starting index.
                    firstType = lastType;
                    firstIndex = lastIndex;

                    // Set last type to the current fruit.
                    lastType = fruits[i];
                }
                // Update the last index to the current position.
                lastIndex = i;
            }
        }

        // After the loop, update the max sequence length one last time to cover the end of the array.
        return max(maxSequence, (int)fruits.size() - firstIndex);
    }
};
