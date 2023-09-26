class Solution {
public:
	int sum(int i,vector<int>& nums){
		int p1=nums[0],p2;
		for(int i=1;i<nums.size();i++){
			int pick=nums[i];
			if(i!=1)pick+=p2;
			int notpick=p1;
			int curri=max(pick,notpick);
			p2=p1;
			p1=curri;
		}
		return p1;
	}

	int rob(vector<int>& nums) {
		int n=nums.size();
		if(n==1)return nums[0];
		vector<int>nums1,nums2;
		for(int i=0;i<n;i++){
			if(i!=0)nums1.push_back(nums[i]);
			if(i!=n-1)nums2.push_back(nums[i]);
		}
		return max(sum(n-2,nums1),sum(n-2,nums2)); 
	}
};