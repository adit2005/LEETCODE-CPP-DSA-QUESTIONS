class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        if (a.size() == 0)  return 0;
        int mod = pow(10, 9) + 7;
        stack<pair <int, int>> s1,s2;
        int left[a.size()],right[a.size()];
        for(int i=0;i<a.size();i++){
            int count=1;
            while(!s1.empty()&& s1.top().first>=a[i]){
                count+=s1.top().second;
                s1.pop();
            }
            s1.push(make_pair(a[i],count));
            left[i]=count;
        }
        for(int i=a.size()-1;i>=0;i--){
            int count=1;
            while(!s2.empty()&& s2.top().first>a[i]){
                count+=s2.top().second;
                s2.pop();
            }
            s2.push(make_pair(a[i],count));
            right[i]=count;
        }
        int ans=0;
        for(int i=0;i<a.size();i++){
            long long prod = (left[i]*right[i])%mod;
            prod = (prod*a[i])%mod;
            ans = (ans + prod)%mod;
        }
        return ans;
    }
};