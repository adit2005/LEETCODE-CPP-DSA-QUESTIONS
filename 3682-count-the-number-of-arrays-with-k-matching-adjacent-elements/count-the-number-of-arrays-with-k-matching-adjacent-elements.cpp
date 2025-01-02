class Solution {
private:
    static const int MOD = 1000000007;
    static const int MAXN = 100000;
    vector<long long> fact, invFact;

    // Function to compute base^exp % mod
    long long modExp(long long base, int exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    // Precomputing factorials and modular inverses
    void precompute() {
        fact.resize(MAXN + 1);
        invFact.resize(MAXN + 1);
        fact[0] = 1;
        for (int i = 1; i <= MAXN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[MAXN] = modExp(fact[MAXN], MOD - 2, MOD);
        for (int i = MAXN - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    // Function to compute nCr % MOD
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

public:
    Solution() {
        precompute(); // Initialize factorials and inverse factorials
    }

    int countGoodArrays(int n, int m, int k) {
        if (n == 1) return (k == 0) ? m : 0;

        long long choose = nCr(n - 1, k);
        long long ways = choose % MOD;

        ways = (ways * m) % MOD;
        ways = (ways * modExp(m - 1, n - k - 1, MOD)) % MOD;

        return (int)ways;
    }
};
