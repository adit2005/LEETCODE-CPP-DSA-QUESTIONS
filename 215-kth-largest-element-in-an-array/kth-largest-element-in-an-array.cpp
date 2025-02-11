class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            max_heap.pop();
        }
        return max_heap.top();
    }
};