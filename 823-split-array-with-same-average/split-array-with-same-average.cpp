unordered_map<string,bool>mp;

int solve(int ind,int s1,int siz,vector<int>&v)
{
    if(ind>=v.size())
        return s1==0&&siz==0;
    
    if(siz==0)
        return s1==0;
    
    string k=to_string(ind)+" "+to_string(s1)+" "+to_string(siz);

    if(mp.find(k)!=mp.end())
        return mp[k];
    
    mp[k]=false;

    if(v[ind]<=s1)
        mp[k]|=solve(ind+1,s1-v[ind],siz-1,v);
    
    if(mp[k])
        return 1;

    return mp[k]|=solve(ind+1,s1,siz,v);
}


class Solution {
public:
    bool splitArraySameAverage(vector<int>& v) {
        //s1+s2=s
        //n1+n2=n
        //s1/n1=s2/n2 --> s2=(n-n1)s1/n1
        //s1=s*n1/n

        mp.clear();

        int s=0;

        for(auto i:v)
            s+=i;
        
        int n=v.size();
        
        for(int i=1;i<n;++i)
        {
            if((s*i)%n==0)
            {
                int s1=s*i;
                s1/=n;
                
                if(solve(0,s1,i,v))
                    return true;
            }
        }
        return false;
    }
};