class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<pair<int, vector<int>>> st;  // Set to store sum and indices for each combination
        pair<int, vector<int>> vec;      // Pair to hold current sum and indices
        for(int i = 0; i < mat.size(); i++) {
            vec.second.push_back(0);   // Initialize all indices to 0
            vec.first += mat[i][0];    // Initialize the sum with the first element of each row
        }
        st.insert(vec);  // Insert the initial state into the set
        if(k == 1) {
            return vec.first;  // If k is 1, return the smallest sum immediately
        }
        while(k > 1) {  
            auto it = st.begin();  // Get the smallest sum from the set
            pair<int, vector<int>> a = (*it);
            st.erase(st.begin());  // Remove the smallest element from the set
            for(int i = 0; i < mat.size(); i++) {
                if(a.second[i] + 1 < mat[i].size()) {
                    a.first += mat[i][a.second[i] + 1] - mat[i][a.second[i]];  // Update the sum
                    a.second[i]++;  // Increment the index for the current row
                    st.insert(a);  // Insert the updated pair into the set
                    a.second[i]--;  // Revert the index for the next iteration
                    a.first += mat[i][a.second[i]] - mat[i][a.second[i] + 1];  // Revert the sum
                }
            }
            k--;  // Decrement k after processing one combination
        }
        auto temp = st.begin();  // Get the k-th smallest sum
        int ans = (*temp).first;  // Extract the smallest sum from the set
        return ans;  // Return the result
    }
};

