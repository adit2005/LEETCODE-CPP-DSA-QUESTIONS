class Solution {
public:
    using ll=long long;
    long long minEnd(ll n, ll x) {
        /*
            x : 110000010001
            anything set in x is set in every num
        */
        if(n==1) return x;
        ll res=0,g=0;
        for(ll bit=0;bit<32;bit++,g++) {
            while(x>>g&1) g++;
            if((n-1)>>bit&1) {
                res|=(1ll<<g);
            }
            
        }
        return res|x;
    }
};