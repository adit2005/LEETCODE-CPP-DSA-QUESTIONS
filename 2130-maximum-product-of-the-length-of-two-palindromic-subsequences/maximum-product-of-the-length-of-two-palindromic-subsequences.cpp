class Solution {
public:
    int palSize(string &s, int mask) {
        int p1 = 0, p2 = s.size(), res = 0;
        while (p1 <= p2) {
            if ((mask & (1 << p1)) == 0)
                ++p1;
            else if ((mask & (1 << p2)) == 0)
                --p2;
            else if (s[p1] != s[p2])
                return 0;
            else
                res += 1 + (p1++ != p2--);
        }
        return res;
    }

    int maxProduct(string s) {
        int dp[4096] = {}; // dp array to store the lengths of palindromic substrings for each mask
        int res = 0; // result variable to store the maximum product
        int mask = (1 << s.size()) - 1; // mask representing all positions in the string

        // Calculate the length of the longest palindrome for each possible mask
        for (int m = 1; m <= mask; ++m)
            dp[m] = palSize(s, m);

        // Iterate through all possible masks
        for (int m1 = mask; m1; --m1) {
            // Iterate through all possible complementary masks
            for (int m2 = mask ^ m1; m2; m2 = (m2 - 1) & (mask ^ m1)) {
                // Calculate the product of palindrome lengths for this combination of masks
                int product = dp[m1] * dp[m2];
                // Update the result if this product is greater than the current maximum
                if (product > res)
                    res = product;
            }
        }

        // Return the maximum product of palindrome lengths
        return res;
    }
};
