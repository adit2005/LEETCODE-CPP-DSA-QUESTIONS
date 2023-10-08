class Solution {
public:
    int dotProductMatrix[505][505];  // Dynamic programming array
    int nums1_size, nums2_size;  // Sizes of nums1 and nums2 arrays

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        nums1_size = nums1.size();
        nums2_size = nums2.size();

        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        // Calculate maximum and minimum values for nums1
        for (int num : nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        // Calculate maximum and minimum values for nums2
        for (int num : nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }

        // Check special cases where all elements are negative
        if ((firstMax < 0 && secondMin > 0) || (firstMin > 0 && secondMax < 0)) {
            return max(firstMax * secondMin, firstMin * secondMax);
        }

        memset(dotProductMatrix, 0, sizeof dotProductMatrix);  // Initialize the dot product matrix

        // Calculate dot products and populate the dot product matrix
        for (int i = nums1_size - 1; i >= 0; i--) {
            for (int j = nums2_size - 1; j >= 0; j--) {
                int currentDotProduct = nums1[i] * nums2[j] + dotProductMatrix[i + 1][j + 1];
                dotProductMatrix[i][j] = max({currentDotProduct, dotProductMatrix[i + 1][j], dotProductMatrix[i][j + 1]});
            }
        }
        return dotProductMatrix[0][0];  // Return the maximum dot product
    }
};