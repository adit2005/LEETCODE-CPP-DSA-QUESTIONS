class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());

        // Precompute factorials and modular inverses for combinations
        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        for (int i = 0; i <= n; i++) {
            invFact[i] = modInverse(fact[i], MOD);
        }

        // Lambda to calculate combinations
        auto comb = [&](int a, int b) -> long long {
            if (b > a || b < 0) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };

        long long result = 0;

        // Calculate contributions for each element
        for (int i = 0; i < n; i++) {
            long long minContrib = 0, maxContrib = 0;

            // Ways nums[i] can be the minimum
            for (int j = 0; j <= k - 1; j++) {
                minContrib = (minContrib + comb(i, j)) % MOD;
            }

            // Ways nums[i] can be the maximum
            for (int j = 0; j <= k - 1; j++) {
                maxContrib = (maxContrib + comb(n - i - 1, j)) % MOD;
            }

            // Add contributions to the result
            result = (result + nums[i] * (minContrib + maxContrib) % MOD) % MOD;
        }

        return result;
    }

private:
    // Function to calculate modular inverse using Fermat's Little Theorem
    long long modInverse(long long a, long long m) {
        long long res = 1, exp = m - 2;
        while (exp) {
            if (exp % 2) res = (res * a) % m;
            a = (a * a) % m;
            exp /= 2;
        }
        return res;
    }
};
