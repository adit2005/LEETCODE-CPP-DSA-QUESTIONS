class Solution {
public:
    void rec(int i, vector<int>& ans,int n,int k,int cur, long long num){
        if(cur==n){
            ans.push_back(num);
            return;
        }
        for(int j=0;j<10;j++){
            if(abs(j-i)!=k) continue;
            num=num*10+j;
            rec(j,ans,n,k,++cur,num);
            num=(num-j) / 10;
            cur--;
        }
       // return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<10;i++){
            rec(i,ans,n,k,1,i);
        }
        return ans;
    }
};