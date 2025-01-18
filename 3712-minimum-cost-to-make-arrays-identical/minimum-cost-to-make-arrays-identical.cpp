class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        
        // Vectors to store the indices where elements differ
        vector<int> arr_diff, brr_diff;
        long long int sum2 = 0 ; 

        // Separate indices where arr[i] != brr[i]
        for (int i = 0; i < n; ++i) {
            if (arr[i] != brr[i]) {
                arr_diff.push_back(arr[i]);
                brr_diff.push_back(brr[i]);
            }

            sum2 += abs(arr[i] - brr[i]);
        }
         vector<int> sorted_diff1 = arr_diff;
          vector<int> sorted_diff2 = brr_diff;

        // Sort both vectors
        sort(arr_diff.begin(), arr_diff.end());
        sort(brr_diff.begin(), brr_diff.end());
         

        // Calculate the cost of making the arrays identical
        long long diff_cost = 0;
        for (int i = 0; i < arr_diff.size(); ++i) {
            diff_cost += abs(arr_diff[i] - brr_diff[i]);
        }

        // Check if rearrangement is needed
        bool need_rearranging = (sorted_diff1!= arr_diff) || (sorted_diff2 != brr_diff);
        
        // Add rearranging cost if needed
        if (need_rearranging) {
            diff_cost += k;
        }

        return min(diff_cost, sum2);
    }
};
