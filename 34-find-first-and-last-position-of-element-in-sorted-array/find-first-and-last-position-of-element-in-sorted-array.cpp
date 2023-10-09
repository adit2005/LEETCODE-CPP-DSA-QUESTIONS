class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

 
        int n = nums.size();
        int left = -1, right = -1;
        
        // binary search to find leftmost occurrence
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] >= target) {
                high = mid - 1;
                if (nums[mid] == target) {
                    left = mid;
                }
            }
        }
        
        // binary search to find rightmost occurrence
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] <= target) {
                low = mid + 1;
                if (nums[mid] == target) {
                    right = mid;
                }
            }
        }
        
        return {left, right};
    }
};