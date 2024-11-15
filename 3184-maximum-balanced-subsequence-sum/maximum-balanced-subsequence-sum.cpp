#define ll long long

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> val(n);
        
        // Compute val[i] = nums[i] - i
        for (int i = 0; i < n; i++) {
            val[i] = nums[i] - i;
        }

        // Map to store maximum sum for each key, and set to track keys
        map<int, ll> mp;
        set<int> st;

        // Initialize the first value
        st.insert(val[0]);
        mp[val[0]] = nums[0];
        ll ans = nums[0];

        for (int i = 1; i < n; i++) {
            // Find the largest key <= val[i]
            auto it = st.upper_bound(val[i]);
            if (it != st.begin()) {
                it--; // Move to valid key
                mp[val[i]] = max(nums[i] + mp[*it], 1LL * nums[i]);
            } else {
                mp[val[i]] = nums[i]; // No valid previous key
            }

            // Remove suboptimal keys
            it = st.upper_bound(val[i]);
            while (it != st.end() && mp[*it] <= mp[val[i]] && *it > val[i]) {
                st.erase(it++);
            }

            // Insert the current key into the set
            st.insert(val[i]);

            // Update the maximum answer
            ans = max(ans, mp[val[i]]);
        }

        return ans;
    }
};
