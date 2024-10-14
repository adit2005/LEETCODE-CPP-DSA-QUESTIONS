class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
    // Create an array to count occurrences of each barcode number (0 to 10000)
    short m[10001] = {};
    
    // Initialize variables to track the maximum count and the corresponding barcode number
    short max_cnt = 0, max_n = 0, pos = 0;

    // Count the frequency of each barcode number
    for (auto n : b) {
        // Increment the count for this barcode number
        max_cnt = max(max_cnt, ++m[n]); // Update max_cnt to the highest frequency found
        // Update max_n to the current number if it has the maximum frequency
        max_n = max_cnt == m[n] ? n : max_n;
    }

    // Rearrange the barcodes in the result vector
    for (auto i = 0; i <= 10000; ++i) {
        // Get the barcode number to place; use max_n first, then go from 1 to 10000
        auto n = i == 0 ? max_n : i; 
        
        // While there are still occurrences of the current barcode number
        while (m[n]-- > 0) {
            // Place the barcode number at the current position
            b[pos] = n;

            // Update position to the next available index (skip to the next even index, or wrap to the first odd index)
            pos = pos + 2 < b.size() ? pos + 2 : 1;
        }
    }

    // Return the rearranged barcode vector
    return b;
}

};