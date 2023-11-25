class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        vector<int>ans;
        int sum=0,cur=0,n=nums.size(),i;
        for(auto &it:nums)
            sum+=it;
        for(i=0;i<n;i++){
            cur+=nums[i];
            int low=((nums[i]*(i+1))-cur);
            int high=(sum-cur)-(nums[i]*(n-(i+1)));
            ans.push_back(low+high);
        }
        return ans;
    }
};