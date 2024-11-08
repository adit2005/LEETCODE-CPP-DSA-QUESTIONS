class Solution {
public:
    bool isBalanced(string num) {
        int evenSum = 0;  // Sum of digits at even indices
        int oddSum = 0;   // Sum of digits at odd indices

        // Iterate through the string
        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';  // Convert character to integer

            if (i % 2 == 0) {  // Even index
                evenSum += digit;
            } else {            // Odd index
                oddSum += digit;
            }
        }

        // Check if the sums are equal
        return evenSum == oddSum;
    }
};
