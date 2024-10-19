class Solution {
public:
    char findKthBit(int n, int k) {
        // Track the number of inversions
        int invertCount = 0;

        // Calculate the length of Sn as 2^n - 1
        int len = (1 << n) - 1;

        // Loop until k becomes 1 (the base case)
        while (k > 1) {
            // If k is exactly in the middle, it represents the '1' added during construction
            if (k == (len + 1) / 2) {
                // If the number of inversions is even, the middle bit is '1'
                // If odd, it flips to '0'
                return (invertCount % 2 == 0) ? '1' : '0';
            }

            // If k is in the second half of the current string
            if (k > (len + 1) / 2) {
                // Update k to its mirrored position in the first half
                k = len + 1 - k;
                // Increment invertCount as we've crossed into an inverted section
                invertCount++;
            }

            // Halve the length of the current string
            len = (len - 1) / 2;
        }

        // After the loop, k is 1, corresponding to the first bit of S1
        // Return '0' if the invertCount is even, otherwise '1'
        return (invertCount % 2 == 0) ? '0' : '1';
    }
};
