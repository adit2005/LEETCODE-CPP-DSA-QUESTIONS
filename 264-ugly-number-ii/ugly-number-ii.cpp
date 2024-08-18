class Solution {
public:
    int nthUglyNumber(int n) {
        // Base case: if n is less than or equal to 0, it's not valid, return false
        if(n <= 0) return false;
        // If n is 1, the first ugly number is always 1, so return true
        if(n == 1) return true;

        // Initialize three pointers for multiples of 2, 3, and 5
        int t2 = 0, t3 = 0, t5 = 0;

        // Create a vector to store the first 'n' ugly numbers
        vector<int> k(n);
        // The first ugly number is 1 by definition
        k[0]  = 1;

        // Generate ugly numbers from 2 to n
        for(int i = 1; i < n; i++) {
            // The next ugly number is the minimum among the next multiples of 2, 3, and 5
            k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));

            // If the current ugly number was produced by multiplying with 2, increment the pointer for 2
            if(k[i] == k[t2] * 2) t2++;

            // If the current ugly number was produced by multiplying with 3, increment the pointer for 3
            if(k[i] == k[t3] * 3) t3++;

            // If the current ugly number was produced by multiplying with 5, increment the pointer for 5
            if(k[i] == k[t5] * 5) t5++;
        }

        // The last element in the vector is the nth ugly number
        return k[n-1];
    }
};
