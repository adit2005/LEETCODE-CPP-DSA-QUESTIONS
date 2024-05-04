class Solution {
public:
    // Function to perform binary search to find the index of the last job that finishes before the start time of the current job
    int binarySearch(const vector<vector<int>>& jobs, int end, int left, int right) {
        int result = -1; // Initialize result to -1

        // Binary search loop
        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate mid index
            
            // If the end time of the job at mid index is less than or equal to the given end time
            if (jobs[mid][1] <= end) {
                result = mid; // Update result to mid
                left = mid + 1; // Move left pointer to mid + 1
            } else {
                right = mid - 1; // Move right pointer to mid - 1
            }
        }

        return result; // Return the index of the last job that finishes before the start time of the current job
    }

    // Function to solve the job scheduling problem
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(); // Get the number of jobs
        int dp[n]; // Create an array to store the maximum profit for each job
        vector<vector<int>> jobs(n, vector<int>(3)); // Create a 2D vector to store the jobs

        // Populate the jobs vector with the start time, end time, and profit for each job
        for(int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        // Sort the jobs vector based on the end times of the jobs in ascending order
        sort(jobs.begin(), jobs.end(), [](const vector<int>& m, const vector<int>& n) {
            return m[1] < n[1];
        });
 
        // Initialize the maximum profit for the first job
        dp[0] = jobs[0][2];

        // Iterate over each job starting from the second one
        for (int i = 1; i < n; i++) {
            int prev = 0; // Initialize the profit from the previous job to 0

            // Use binary search function to find the index of the last job that finishes before the start time of the current job
            int lastJobIndex = binarySearch(jobs, jobs[i][0], 0, i - 1);
            if (lastJobIndex != -1) {
                prev = dp[lastJobIndex]; // Update the profit from the previous job
            }

            // Calculate the maximum profit for the current job by considering whether to include the current job or not
            dp[i] = max(prev + jobs[i][2], dp[i-1]);
        }
        
        return dp[n - 1]; // Return the maximum profit that can be achieved by scheduling the jobs
    }
};
