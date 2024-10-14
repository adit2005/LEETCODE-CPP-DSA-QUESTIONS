class Solution {
public:
    // Function to rearrange barcodes
    vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
        // Create a frequency map to count occurrences of each barcode number
        unordered_map<int, int> m;

        // Create a set to store barcode numbers along with their frequencies
        // The set is ordered by the frequency in descending order
        set<pair<int, int>> s;

        // Count the frequency of each barcode number
        for (auto n : b) ++m[n];

        // Insert the frequency and the barcode number into the set
        // The pair is structured as (frequency, barcode number)
        for (auto it = begin(m); it != end(m); ++it) 
            s.insert({ it->second, it->first });

        // Iterate over the set in reverse order to get the highest frequency first
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            // For each barcode, place it in the result vector based on its frequency
            for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2) {
                // If we reach the end of the vector, wrap around to position 1
                if (pos >= b.size()) pos = 1;

                // Place the barcode number at the current position
                b[pos] = it->second;
            }
        }
        // Return the rearranged barcode vector
        return b;
    }
};

