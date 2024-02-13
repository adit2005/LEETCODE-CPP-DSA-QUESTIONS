class Solution {
public:
const int prime = 1e9 + 7;

    int count(string s, string t, int ind1, int ind2, vector<vector<int>>& dp) {
    
    if (ind2 < 0)
        return 1;
    
   
    if (ind1 < 0)
        return 0;

   
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

   
    if (s[ind1] == t[ind2]) {
        int leaveOne = count(s, t, ind1 - 1, ind2 - 1, dp);
        int stay = count(s, t, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;
    } else {
        
        result = count(s, t, ind1 - 1, ind2, dp);
    }

 
    dp[ind1][ind2] = result;
    return result;
}
    int numDistinct(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        return count(s, t, l1 - 1, l2 - 1, dp);
    }
};