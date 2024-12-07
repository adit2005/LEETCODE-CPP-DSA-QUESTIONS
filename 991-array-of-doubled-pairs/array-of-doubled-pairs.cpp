class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        // Step 1: Create a frequency map
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Sort the array by absolute values
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        // Step 3: Process each number
        for (int num : arr) {
            if (freq[num] == 0) continue; // Skip if already processed

            // Check if the double exists
            if (freq[2 * num] == 0) {
                return false;
            }

            // Decrement counts for the current number and its double
            freq[num]--;
            freq[2 * num]--;
        }

        // Step 4: Check if the frequency map is empty
        for (auto [key, value] : freq) {
            if (value > 0) {
                return false;
            }
        }

        return true;
    }
};