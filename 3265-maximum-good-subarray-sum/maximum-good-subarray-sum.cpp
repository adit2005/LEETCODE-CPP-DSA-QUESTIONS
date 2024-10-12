class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=LLONG_MIN;
        vector<long long>pre(nums.size()+1);
        pre[0]=0;
        for(int i = 1; i <= nums.size(); i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        unordered_map<int,int>mp;
        
       
        for(int i = 0; i < nums.size(); i++){
            int curEle=nums[i];
            if(mp.find(curEle-k)!=mp.end()){
                ans=max(ans,pre[i+1]-pre[mp[curEle-k]]);
            }
            if(mp.find(curEle+k)!=mp.end()){
                ans=max(ans,pre[i+1]-pre[mp[curEle+k]]);
            }
            if(mp.find(curEle)!=mp.end()){
               if(pre[i]-pre[mp[curEle]]<=0)
               mp[curEle]=i;
            }
            else mp[curEle]=i;
            
        }
        if(ans==LLONG_MIN)return 0;
        return ans;
    }
};