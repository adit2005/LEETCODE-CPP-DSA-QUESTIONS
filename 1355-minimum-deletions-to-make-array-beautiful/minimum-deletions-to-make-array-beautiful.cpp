class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int>st;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.empty())
            {
                st.push(nums[i]);
            }
            else
            {
                if((i-ans)%2!=0 and st.top()==nums[i])
                {
                    st.pop();
                    ans++;
                }
                st.push(nums[i]);
            }
        }
        if((nums.size()-ans)%2!=0)
        {
            ans++;
        }
        return ans;
    }
};