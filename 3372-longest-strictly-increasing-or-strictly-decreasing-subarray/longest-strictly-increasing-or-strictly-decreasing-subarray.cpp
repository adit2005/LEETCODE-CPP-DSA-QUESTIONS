class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 1;
        int count2=1;
        int count1=1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                count1++;
            } 
            else {
                maxLength = max(maxLength, count1);
                
                count1=1;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                
                count2++;
            } 
            else {
                maxLength = max(maxLength, count2);
                count2 = 1;
            }
        }

        maxLength=max(maxLength, count2);
        maxLength=max(maxLength, count1);
        return maxLength;
        
    }
};