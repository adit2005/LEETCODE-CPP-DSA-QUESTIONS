#define ll long long 

class Solution {
public:
    // Helper function to calculate 2 raised to the power x
    ll power(int x) {
        ll res = 1;   // Initialize result as 1 (2^0)
        for(int i = 0; i < x; i++) { 
            res *= 2; // Multiply res by 2 for each iteration, effectively calculating 2^x
        }
        return res;   // Return the result as 2^x
    }

    int minOperations(int n) {
        if(n == 0) return 0;  // Base case: if n is 0, no operations are needed

        // Find the largest power of 2 that is less than or equal to `n`
        int pt = log2(n);  // `pt` is the highest power of 2 that is <= n

        // Calculate the closest powers of 2 to `n`
        int mn = power(pt);      // `mn` is 2^pt, the largest power of 2 less than or equal to n
        int mx = power(pt + 1);  // `mx` is 2^(pt + 1), the smallest power of 2 greater than n

        // Calculate the differences to the closest powers of 2
        int diff1 = n - mn; // Difference if we reduce `n` by the lower power (n - 2^pt)
        int diff2 = mx - n; // Difference if we increase `n` to the higher power (2^(pt + 1) - n)

        // Recursively choose the operation that minimizes the steps
        if(diff1 > diff2) {
            // If `diff2` (distance to the higher power) is smaller, move towards `mx`
            return 1 + minOperations(diff2);
        } else {
            // Otherwise, move towards `mn`
            return 1 + minOperations(diff1);
        }
    }
};
