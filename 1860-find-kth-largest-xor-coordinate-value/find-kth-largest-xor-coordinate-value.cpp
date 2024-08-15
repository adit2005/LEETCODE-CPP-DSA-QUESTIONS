class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
    int i, j, n = matrix.size(), m = matrix[0].size();
    // Min-heap to store the k largest elements encountered so far
    priority_queue<int, vector<int>, greater<int>> pq;

    // Step 1: Compute the prefix XOR for each row
    // This loop calculates the cumulative XOR for each row from left to right.
    // After this step, each matrix[i][j] holds the XOR of all elements in the row from the first column to the j-th column.
    for (i = 0; i < n; i++) {
        for (j = 1; j < m; j++) {
            matrix[i][j] = matrix[i][j-1] ^ matrix[i][j];
        }
    }

    // Step 2: Compute the prefix XOR for each column
    // This loop calculates the cumulative XOR for each column from top to bottom.
    // After this step, each matrix[i][j] holds the XOR of all elements in the submatrix starting from (0,0) to (i,j).
    for (i = 0; i < m; i++) {
        for (j = 1; j < n; j++) {
            matrix[j][i] = matrix[j-1][i] ^ matrix[j][i];
        }
    }

    // Step 3: Identify the k-th largest value
    // Traverse through the matrix and use a min-heap to maintain the k largest values.
    // If the size of the heap is less than k, push the current value.
    // If the current value is greater than the smallest value in the heap (pq.top()), replace the smallest value.
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (pq.size() < k) {
                pq.push(matrix[i][j]);
            } else {
                if (matrix[i][j] > pq.top()) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
    }

    // The top of the min-heap now contains the k-th largest element.
    return pq.top();
}

};