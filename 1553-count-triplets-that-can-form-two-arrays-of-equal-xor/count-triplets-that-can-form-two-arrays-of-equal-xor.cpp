class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXOR(arr.begin(), arr.end());
        prefixXOR.insert(prefixXOR.begin(), 0);
        int size = prefixXOR.size();

        // Perform XOR on consecutive elements in the modified array
        for (int i = 1; i < size; ++i) prefixXOR[i] ^= prefixXOR[i - 1];

        int count = 0;

        // Iterate through the prefix XOR array to count triplets
        for (int start = 0; start < size; ++start) {
            for (int end = start + 1; end < size; ++end) {
                if (prefixXOR[start] == prefixXOR[end]) {
                    // Increment the result by the count of valid triplets
                    count += end - start - 1;
                }
            }
        }

        return count;
    }
};