class Solution {
public:
    // Function to merge two halves of the array and count the smaller elements
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right) {
        // Temporary array to store merged results
        vector<pair<int, int>> tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;

        while (i <= mid && j <= right) {
            // Sorting in descending order
            if (v[i].first <= v[j].first) { 
                tmp[k++] = v[j++];
            } else {
                // Update the count for the current element
                // Since v[i].first > v[j].first, all elements from v[j] to v[right] are smaller than v[i]
                count[v[i].second] += right - j + 1;
                tmp[k++] = v[i++];
            }
        }
        // Copy remaining elements from the left half
        while (i <= mid) {
            tmp[k++] = v[i++];
        }
        // Copy remaining elements from the right half
        while (j <= right) {
            tmp[k++] = v[j++];
        }
        // Copy merged results back to the original array
        for (int i = left; i <= right; i++) {
            v[i] = tmp[i-left];
        }
    }        

    // Function to perform merge sort and count smaller elements
    void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int left, int right) {
        if (left >= right) 
            return;

        int mid = left + (right-left)/2;
        // Sort and count the left half
        mergeSort(count, v, left, mid);
        // Sort and count the right half
        mergeSort(count, v, mid+1, right);
        // Merge the two halves and count smaller elements
        merge(count, v, left, mid, right);
    }

    // Main function to count smaller elements
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        // Create a vector of pairs to store the value and its original index
        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; i++)   
            v[i] = make_pair(nums[i], i);

        // Initialize the count array with zeros
        vector<int> count(N, 0);
        // Perform merge sort to count smaller elements
        mergeSort(count, v, 0, N-1);

        return count;
    }
};
