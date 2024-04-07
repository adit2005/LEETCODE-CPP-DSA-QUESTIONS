class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,0));
        dp[s.size()][0]=1;

        for(int ind=s.size()-1; ind>=0; ind--){
            for(int openingBracket=0; openingBracket<s.size(); openingBracket++){
                bool ans=false;
                if(s[ind]=='*'){
                    ans|=dp[ind+1][openingBracket+1];
                    if(openingBracket) ans|=dp[ind+1][openingBracket-1];
                    ans|=dp[ind+1][openingBracket];
                }else{
                    if(s[ind]=='('){
                        ans|=dp[ind+1][openingBracket+1];
                    }else{
                        if(openingBracket) ans|=dp[ind+1][openingBracket-1];
                    }
                }

                dp[ind][openingBracket]=ans;
            }
        }

        return dp[0][0];
    }
};