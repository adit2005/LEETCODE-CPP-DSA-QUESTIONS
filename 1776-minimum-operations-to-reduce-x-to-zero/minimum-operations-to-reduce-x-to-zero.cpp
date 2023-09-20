class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target=0,n=nums.size();
        for(int num:nums) target+=num;
        target-=x;
        if(target==0) return n;
        int len=0,sum=0,left=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(left<=right and sum>target){
                sum-=nums[left];
                left++;
            }
            if(sum==target) len=max(len,right-left+1);
        }
        return (len>0)?(n-len):-1;
    }
};