class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return false;
        }

        stack<int>st;
        int max2 = INT_MIN;

        for(int i = n-1; i>= 0; i--){
            if(nums[i] < max2){
                return true;
            }

            while(!st.empty() && nums[i] > st.top()){
                max2 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};