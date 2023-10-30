class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // Create a vector to store the sorted values
        vector<int> ans;

        // Create a vector of pairs to store the count of set bits (1s) and the original values
        vector<pair<int,int>> v;

        // Iterate through the input array
        for (auto val: arr){
            int dem = val; // Store the current value in 'dem'
            int cnt = 0;   // Initialize a count to 0 to count set bits

            // Count the set bits in 'dem' using bitwise operations
            while (dem > 0){
                cnt += (dem & 1); // Check the least significant bit and add it to the count
                dem = dem >> 1;   // Right shift 'dem' to check the next bit
            }

            // Add a pair to the 'v' vector containing the count and the original value
            v.push_back({cnt, val});
        }

        // Sort the 'v' vector based on the count of set bits
        sort(v.begin(), v.end());

        // Iterate through the sorted pairs and add the original values to the 'ans' vector
        for (auto val: v)
            ans.push_back(val.second);

        // Return the sorted 'ans' vector
        return ans;
    }
};
