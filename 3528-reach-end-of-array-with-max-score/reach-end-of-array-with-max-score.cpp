class Solution {
public:
    long long findMaximumScore(vector<int>& nums) 
    {
        long long ans = 0;
        int j = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > nums[j])
            {
                ans += (long(nums[j]) * abs(i - j));
                j = i;
            }
        }
        
        ans += (long(nums[j]) * (n - j - 1));
        
        return ans;   
    }
};
