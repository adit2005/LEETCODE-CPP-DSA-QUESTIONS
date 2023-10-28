class Solution {
public:
    int MOD = 1e9 + 7;

    // Recursive function to calculate the count of valid permutations
    long long int f(int n, int i, char c, vector<vector<int>> &dp, unordered_map<char, int> &mp) {
        // If we've reached the desired length, return 1 (a valid permutation)
        if (i == n) return 1;

        long long count = 0;

        // If we've already computed the result for this character 'c' and position 'i', return it
        if (dp[mp[c]][i] != -1) return dp[mp[c]][i] % MOD;

        // Check the allowed characters that can follow the current character 'c'
        if (c == 'a') {
            // After 'a', only 'e' is allowed
            count += f(n, i + 1, 'e', dp, mp);
        }

        if (c == 'e') {
            // After 'e', 'a' and 'i' are allowed
            count += f(n, i + 1, 'a', dp, mp);
            count += f(n, i + 1, 'i', dp, mp);
        }

        if (c == 'i') {
            // After 'i', any character except 'i' is allowed
            count += f(n, i + 1, 'a', dp, mp);
            count += f(n, i + 1, 'e', dp, mp);
            count += f(n, i + 1, 'o', dp, mp);
            count += f(n, i + 1, 'u', dp, mp);
        }

        if (c == 'o') {
            // After 'o', only 'i' and 'u' are allowed
            count += f(n, i + 1, 'i', dp, mp);
            count += f(n, i + 1, 'u', dp, mp);
        }

        if (c == 'u') {
            // After 'u', only 'a' is allowed
            count += f(n, i + 1, 'a', dp, mp);
        }

        // Store the result in the memoization table and return it modulo MOD
        return dp[mp[c]][i] = count % MOD;
    }

    int countVowelPermutation(int n) {
        // Map to convert char to int for using in the memoization table (dp)
        unordered_map<char, int> mp;
        mp['a'] = 0;
        mp['e'] = 1;
        mp['i'] = 2;
        mp['o'] = 3;
        mp['u'] = 4;

        // Initialize a memoization table (dp) with -1 values
        vector<vector<int>> dp(5, vector<int>(n + 1, -1));

        // Call the recursive function for each starting vowel to consider all possibilities
        long long cnt = f(n, 1, 'a', dp, mp) + f(n, 1, 'e', dp, mp) + f(n, 1, 'i', dp, mp) + f(n, 1, 'o', dp, mp) + f(n, 1, 'u', dp, mp);

        // Return the total count of valid permutations modulo MOD
        return cnt % MOD;
    }
};
