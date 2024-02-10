class Solution {
public:
    string solve(string s,int n)
    {
        if(n==1)
        {
            return s;
        }
       
        int freq=1;
        char ch=s[0];
        string ans="";
        s+="#";
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==ch)
            {
                
                freq++;
            }
            else
            {
               
                ans+=to_string(freq)+ch;
                freq=1;
                ch=s[i];
            }
        }
        return solve(ans,n-1);
    }
    string countAndSay(int n) {
        return solve("1",n);
    }
};