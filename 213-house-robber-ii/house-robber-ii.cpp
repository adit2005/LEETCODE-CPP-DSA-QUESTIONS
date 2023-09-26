class Solution {
public:
	int rob(vector<int>& nums) {
		int n=nums.size();
		if(n==1)return nums[0];
		vector<int>nums1,nums2,dp1(n-1),dp2(n-1);
		for(int i=0;i<n;i++){
			if(i!=0)nums1.push_back(nums[i]);
			if(i!=n-1)nums2.push_back(nums[i]);
		}
		dp1[0]=nums1[0];
		for(int i=1;i<n-1;i++){
			int pick=nums1[i];
			if(i!=1)pick+=dp1[i-2];
			int notpick=dp1[i-1];
			dp1[i]=max(pick,notpick);
		}
		dp2[0]=nums2[0];
		for(int i=1;i<n-1;i++){
			int pick=nums2[i];
			if(i!=1)pick+=dp2[i-2];
			int notpick=dp2[i-1];
			dp2[i]=max(pick,notpick);
		}
		return max(dp1[n-2],dp2[n-2]); 
	}
};