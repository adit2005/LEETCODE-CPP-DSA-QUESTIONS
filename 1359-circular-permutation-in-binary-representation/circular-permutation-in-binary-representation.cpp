class Solution {
public:
    // Function to generate a circular permutation of size 2^n starting from 'start'.
    vector<int> circularPermutation(int n, int start) {
        // Create a vector to hold the numbers of the permutation
        vector<int> permutation(1 << n); // 1 << n is equivalent to 2^n

        // Fill the permutation vector using Gray code logic and applying the start offset.
        for (int i = 0; i < (1 << n); ++i) {
            // Calculate the i-th Gray code by XORing i with its right-shifted self.
            int grayCode = i ^ (i >> 1);
          
            // XOR with 'start' to rotate the permutation so that it begins with 'start'.
            permutation[i] = grayCode ^ start;
        }

        // Return the resulting circular permutation vector.
        return permutation;
    }
};