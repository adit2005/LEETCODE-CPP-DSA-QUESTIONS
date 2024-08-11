class Solution {
public:
    // Function to find the largest number that is a multiple of three
    string largestMultipleOfThree(vector<int>& digits, string res = "") {
        // Arrays to determine which digits to remove if the sum modulo 3 is 1 or 2
        int m1[] = {1, 4, 7, 2, 5, 8}; // Digits with modulo 3 equal to 1
        int m2[] = {2, 5, 8, 1, 4, 7}; // Digits with modulo 3 equal to 2
        
        int sum = 0; // Variable to store the sum of all digits
        int ds[10] = {}; // Array to store the count of each digit from 0 to 9

        // Calculate the sum of digits and populate the digit count array
        for (auto d : digits) {
            ++ds[d]; // Increment the count of the digit 'd'
            sum += d; // Add the digit 'd' to the sum
        }

        // Adjust the sum to make it a multiple of 3 by removing the minimum necessary digits
        while (sum % 3 != 0) {
            // If the sum modulo 3 is 1, we try to remove a digit from m1 array
            // If the sum modulo 3 is 2, we try to remove a digit from m2 array
            for (auto i : sum % 3 == 1 ? m1 : m2) {
                if (ds[i]) { // Check if the digit 'i' is available
                    --ds[i]; // Remove one occurrence of digit 'i'
                    sum -= i; // Subtract the value of the digit 'i' from the sum
                    break; // Exit the loop once a digit is removed
                }
            }
        }

        // Construct the largest possible number from the remaining digits
        for (int i = 9; i >= 0; --i)
            res += string(ds[i], '0' + i); // Append 'ds[i]' occurrences of the digit 'i' to the result string

        // If the result starts with '0', the largest number we can form is "0"
        return res.size() && res[0] == '0' ? "0" : res;
    }
};
