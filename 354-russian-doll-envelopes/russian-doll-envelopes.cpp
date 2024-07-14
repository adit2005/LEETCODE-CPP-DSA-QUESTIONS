class Solution {
public:
    // Comparator function to be used in sorting envelopes
    static bool comp(vector<int> &a, vector<int> &b) {
        // Sort by width in ascending order
        if (a[0] == b[0]) {
            // If widths are equal, sort by height in descending order
            return a[1] > b[1];
        } else {
            // Sort by width in ascending order
            return a[0] < b[0];
        }
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort envelopes based on custom comparator function 'comp'
        sort(envelopes.begin(), envelopes.end(), comp);
        
        // Step 2: Use a temporary vector to store heights of envelopes in an increasing order
        vector<int> temp;
        temp.push_back(envelopes[0][1]); // Initialize with the height of the first envelope
        
        // Step 3: Iterate through sorted envelopes to find the maximum number of envelopes that can be nested
        for (int i = 1; i < envelopes.size(); i++) {
            // If current envelope's height is greater than the last element in 'temp', push it into 'temp'
            if (temp.back() < envelopes[i][1]) {
                temp.push_back(envelopes[i][1]);
            } else {
                // Otherwise, find the first element in 'temp' which is not less than current envelope's height
                auto ind = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin();
                // Replace that element with current envelope's height
                temp[ind] = envelopes[i][1];
            }
        }
        
        // Step 4: Return the size of 'temp', which represents the maximum number of nested envelopes
        return temp.size();
    }
};
