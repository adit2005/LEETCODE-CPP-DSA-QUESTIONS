class Solution {
public:
    const long long mod = 1e9 + 7; // Modulo to prevent overflow
    vector<long long> freq, fact, ifact;
    long long n, sum;
    vector<vector<vector<long long>>> dp;

    // Function to compute a^b % m using binary exponentiation
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    // DP function to count valid permutations
    long long count(long long id, long long take, long long cs) {
        // Base case: If we've considered all digits (id == 10)
        if (id == 10) {
            // Check if we have taken half of the digits and balanced the sum
            if (take == n / 2 && 2 * cs == sum) {
                return (1LL * fact[n / 2] % mod * fact[(n + 1) / 2] % mod) % mod;
            } else {
                return 0;
            }
        }
        
        // If the result for this state is already computed, return it
        if (dp[id][take][cs] != -1) {
            return dp[id][take][cs];
        }

        long long ways = 0;
        // Try different number of occurrences of the current digit
        for (long long i = 0; i <= min(freq[id], n / 2 - take); i++) {
            ways = (ways % mod + (1LL * ifact[i] % mod * ifact[freq[id] - i] % mod) % mod * count(id + 1, take + i, cs + i * id) % mod) % mod;
        }

        return dp[id][take][cs] = ways; // Store result in DP table
    }

    int countBalancedPermutations(string num) {
        n = num.size(); // Store the length of the input string
        sum = 0; // Initialize sum of digits
        freq.resize(10, 0); // Frequency of each digit (0-9)
        fact.resize(n + 1, 1); // Factorial array
        ifact.resize(n + 1); // Inverse factorial array

        // Calculate frequency of digits and the total sum of digits
        for (long long i = 0; i < n; i++) {
            freq[num[i] - '0']++;
            sum += (num[i] - '0');
        }

        // If the sum of digits is odd, return 0 as no balanced permutation is possible
        if (sum % 2) {
            return 0;
        }

        // Precompute factorials and inverse factorials for efficient combinations
        for (long long i = 1; i <= n; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % mod;
        }
        for (long long i = 0; i <= n; i++) {
            ifact[i] = binpow(fact[i], mod - 2, mod) % mod;
        }

        // Initialize DP table with -1 (indicating uncomputed states)
        dp.resize(10, vector<vector<long long>>(n + 1, vector<long long>(sum + 1, -1)));

        // Start counting balanced permutations
        return count(0, 0, 0) % mod;
    }
};
