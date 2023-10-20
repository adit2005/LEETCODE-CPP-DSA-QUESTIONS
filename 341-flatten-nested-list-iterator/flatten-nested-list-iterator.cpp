/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> list; // This vector stores the flattened list of integers.
    int idx; // This variable keeps track of the current index in the list.

    NestedIterator(vector<NestedInteger> &nestedList) {
        listIterator(nestedList); // Initialize the list by flattening the nested list.
        idx = 0; // Initialize the index to the beginning of the list.
    }

    // A recursive function to flatten the nested list and store integers in the 'list' vector.
    void listIterator(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                list.push_back(nestedList[i].getInteger()); // Add the integer to the list.
            } else {
                listIterator(nestedList[i].getList()); // Recursively process nested lists.
            }
        }
    }

    // Return the next integer in the list.
    int next() {
        return list[idx++];
    }

    // Check if there are more integers in the list.
    bool hasNext() {
        return idx < list.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
