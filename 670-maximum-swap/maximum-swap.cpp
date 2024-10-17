class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> lastSeen(10,
                             -1);  // Store the last occurrence of each digit

        // Record the last occurrence of each digit
        for (int i = 0; i < n; ++i) {
            lastSeen[numStr[i] - '0'] = i;
        }

        // Traverse the string to find the first digit that can be swapped with
        // a larger one
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (lastSeen[d] > i) {
                    swap(numStr[i], numStr[lastSeen[d]]);  // Perform the swap
                    return stoi(numStr);  // Return the new number immediately
                                          // after the swap
                }
            }
        }

        return num;  // Return the original number if no swap can maximize it
    }
};