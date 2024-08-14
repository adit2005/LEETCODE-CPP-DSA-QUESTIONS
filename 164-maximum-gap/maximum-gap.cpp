class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long n = nums.size(); // Size of the input array, long long to prevent overflow in index calculations
        int maxi = *max_element(nums.begin(), nums.end()); // Find the maximum element in the array
        int mini = *min_element(nums.begin(), nums.end()); // Find the minimum element in the array

        // If all elements are the same, return 0 as there is no gap
        if(maxi == mini) {
            return 0;
        }

        // Create buckets to track the smallest and largest values in each range
        vector<int> bucketLargest(n, INT_MIN); // Initialize with minimum integer value
        vector<int> bucketSmallest(n, INT_MAX); // Initialize with maximum integer value

        // Distribute elements into their respective buckets
        for(int i = 0; i < n; i++) {
            int index = ((nums[i] - mini) * (n - 1)) / (maxi - mini); // Calculate bucket index
            bucketLargest[index] = max(bucketLargest[index], nums[i]); // Update the largest element in the bucket
            bucketSmallest[index] = min(bucketSmallest[index], nums[i]); // Update the smallest element in the bucket
        }

        int lG = 0; // Variable to store the maximum gap
        int i = 0, j = 1; // Start with the first and second buckets

        // Find the maximum gap by comparing the smallest of the current bucket with the largest of the previous non-empty bucket
        while(j < n) {
            if(bucketLargest[j] == INT_MIN) { // If the current bucket is empty, move to the next one
                j++;
            } else if(bucketLargest[i] == INT_MIN) { // If the previous bucket is empty, move to the next one
                i++;
            } else {
                // Calculate the gap between the smallest in the current bucket and the largest in the previous bucket
                lG = max(lG, bucketSmallest[j] - bucketLargest[i]);
                i++, j++; // Move to the next pair of buckets
            }
        }

        return lG; // Return the maximum gap found
    }
};
