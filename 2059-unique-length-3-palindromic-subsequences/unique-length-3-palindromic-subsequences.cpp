class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans  = 0 ;
         for(char X = 'a'; X <= 'z'; X++){
             int start  = s.find(X);
             int end = s.rfind(X);

             if(end == start) continue;

             for(char Y = 'a'; Y <= 'z'; Y++){
                 int mid = s.find(Y, start+1);
                 if(mid < end && mid!= -1) ans++;
             }
         }

         return ans;
    }
};