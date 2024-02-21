class Solution {
public:
    int helper(vector<int>& stoneValue, int lo, int hi, vector<int>& prefixSum, vector<vector<int>>& dp) {
        
        // Base Case
        if(lo >= hi) {
            return 0;
        }
        if(dp[lo][hi] != -1) {
            return dp[lo][hi];
        }
       
        // Recursive Case
        int ans = 0;
        
        // Iterating to get all the possible values of partition.
        for(int j = lo; j < hi; j++) {
            int mid = j, currAns = 0;
            
            // Getting the leftSum and rightSum using the prefixSum array.
            int leftSum = prefixSum[mid] - prefixSum[lo - 1], rightSum = prefixSum[hi] - prefixSum[mid];
            
            // If Left Sum is greater, then Bob throws away the left row.
            if(leftSum > rightSum) {
                currAns = rightSum + helper(stoneValue, mid + 1, hi, prefixSum, dp);
            } 
            
            // If Right Sum is greater, then Bob throws away the right row.
            else if(leftSum < rightSum){
                currAns = leftSum + helper(stoneValue, lo, mid, prefixSum, dp);
            }
            
            // If both are equal then check for both the left row and the right row and take which ever returns the maximum sum.
            else {
                int takenLeft = leftSum + helper(stoneValue, lo, mid, prefixSum, dp);
                int takenRight = rightSum + helper(stoneValue, mid + 1, hi, prefixSum, dp);
                currAns = max(takenLeft, takenRight);
            }
            ans = max(ans, currAns);
        }
        return dp[lo][hi] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        vector<int>prefixSum;
        prefixSum.push_back(0);
        
        // PrefixSum array
        for(int i = 0; i < stoneValue.size(); i++) {
            prefixSum.push_back(prefixSum.back() + stoneValue[i]);
        }
        vector<vector<int>>dp(stoneValue.size() + 1, vector<int>(stoneValue.size() + 1, -1));
        return helper(stoneValue, 1, stoneValue.size(), prefixSum, dp);
    }
};