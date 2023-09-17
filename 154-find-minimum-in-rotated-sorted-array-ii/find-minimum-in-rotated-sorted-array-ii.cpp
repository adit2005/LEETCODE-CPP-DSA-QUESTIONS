class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,mid,high=nums.size()-1;

        while(low<high){
            mid = low + (high-low)/2;
            if(nums[mid] == nums[high]){
                high--;
            }
            else if(nums[mid] > nums[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }

        return nums[low];
    }
};