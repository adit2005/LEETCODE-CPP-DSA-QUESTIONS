class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1:0;

        for(int index = 2; index<=n; index++){

            if(s[index-1] != '0')
             dp[index] += dp[index-1];

             int twoDigitNum = stoi(s.substr(index-2, 2));
             if(twoDigitNum >= 10 && twoDigitNum <= 26)
               dp[index] += dp[index-2];
        }

        return dp[n];
        
    }
};