class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long z=0,n=s.length();
        for(char c:s) z+=c=='0';
        reverse(s.begin(),s.end());
        long long ans=z;
        for(long long i=0;i<n;i++){
            if(s[i]=='1'){
                if(i>31)return ans;
                long long p=(long long)pow(2,i);
                if(p>k) return ans;
                k-=p,ans++;
            }
        }
        return ans;
    }
};