class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& nums) {
        int n = nums.size();  // Get the number of strings in the input.
        unordered_map<long long, int> mp;  // Hash map to store the count of each unique prefix hash.
        long long mod = 1e15 + 7;  // A large prime number used as a modulus to avoid overflow in hash computation.
        
        // Step 1: Calculate and store the hash of each prefix for all strings.
        for (int i = 0; i < n; i++) {
            long long hash = 0;  // Initialize hash for the current string.
            for (auto &ch : nums[i]) {  // For each character in the current string:
                hash = (hash * 97 + (ch)) % mod;  // Update the hash using the current character.
                mp[hash]++;  // Increment the count of this particular prefix hash in the map.
            }
        }

        // Step 2: Calculate the prefix score for each string.
        vector<int> ans(n, 0);  // Initialize the result vector to store prefix scores for each string.
        for (int i = 0; i < n; i++) {
            int count = 0;  // To store the sum of prefix scores for the current string.
            long long hash = 0;  // Initialize hash for the current string.
            for (auto &ch : nums[i]) {  // For each character in the current string:
                hash = (hash * 97 + (ch)) % mod;  // Recalculate the hash for each prefix.
                count += mp[hash];  // Add the count of this prefix from the hash map to the score.
            }
            ans[i] = count;  // Store the total prefix score for this string.
        }

        return ans;  // Return the vector of prefix scores.
    }
};