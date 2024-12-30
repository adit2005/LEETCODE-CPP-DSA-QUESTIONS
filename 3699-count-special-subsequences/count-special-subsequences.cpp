class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<double, long long> freq;
        long long ans = 0;
        
       
        for (int r = 4; r < nums.size(); ++r) {
            // Update the map for the left side (p, q)
            for (int p = 0, q = r - 2; p < q - 1; ++p) {
                freq[(double)nums[p] / (double)nums[q]]++; // Storing the ratio nums[p] / nums[q]
            }
            
            // Count valid subsequences with (s, r) by checking against the frequency map
            for (int s = r + 2; s < nums.size(); ++s) {
                ans += freq[(double)nums[s] / (double)nums[r]]; // Check if nums[s] / nums[r] exists in freq
            }
        }
        
        return ans; // Return the total count of valid subsequences
    }
};
