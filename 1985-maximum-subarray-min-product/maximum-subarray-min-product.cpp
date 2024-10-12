class Solution {
public:
    int maxSumMinProduct(vector<int>& arr) {
        
        int n = arr.size();
        
        // Large prime number for taking modulus to prevent overflow.
        long long mod = 1e9 + 7;
        
        // Find the prefix sum array to calculate the sum of any subarray efficiently.
        vector<long long> prefix(n, 0);
        prefix[0] = arr[0];
        
        // Calculate prefix sums
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        // Stack to help find the nearest smaller elements.
        stack<int> st;
        
        // Arrays to store the nearest smaller element indices on the left and right.
        vector<int> left(n, -1);  // Initialize with -1 for left boundary.
        vector<int> right(n, n);  // Initialize with n for right boundary.
        
        // Find the index of the next smaller element on the left side for each element.
        for(int i = 0; i < n; i++) {
            // Maintain a stack that will store indices in increasing order of their values in `arr`.
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            // If the stack is empty, it means there's no smaller element on the left.
            if(!st.empty()) {
                left[i] = st.top(); // Store the index of the smaller element.
            }
            
            // Push the current index onto the stack.
            st.push(i);
        }
        
        // Empty the stack to reuse it for finding the right boundary.
        while(!st.empty()) {
            st.pop();
        }
        
        // Find the index of the next smaller element on the right side for each element.
        for(int i = n - 1; i >= 0; i--) {
            // Maintain a stack that will store indices in increasing order of their values in `arr`.
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            // If the stack is not empty, store the index of the smaller element on the right.
            if(!st.empty()) {
                right[i] = st.top();
            }
            
            // Push the current index onto the stack.
            st.push(i);
        }
        
        // Variable to keep track of the maximum min-product.
        long long max_sum = 0;
        
        // Calculate the maximum min-product for each element in `arr`.
        for(int i = 0; i < n; i++) {
            long long sum = 0;
            
            // Calculate the sum of elements from `left[i] + 1` to `right[i] - 1` using prefix sums.
            sum += prefix[right[i] - 1]; // Prefix sum till the element before `right`.
            
            // Subtract the prefix sum up to `left[i]` to get the sum of the subarray.
            if(left[i] >= 0) {
                sum -= prefix[left[i]];
            }
            
            // Multiply the subarray sum by `arr[i]` as it is the minimum element in this range.
            sum *= arr[i];
            
            // Update `max_sum` with the maximum value encountered.
            max_sum = max(max_sum, sum);
        }
        
        // Return the answer modulo `mod` to handle large numbers.
        return max_sum % mod;
    }
};
