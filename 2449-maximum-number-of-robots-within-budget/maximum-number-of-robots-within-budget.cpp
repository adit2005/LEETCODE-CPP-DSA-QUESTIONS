class Solution {
public:
    int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
        long long i = 0, sum = 0, n = times.size();
        multiset<int> s;
        int maxLength = 0; // Variable to store the maximum valid subarray length

        for (int j = 0; j < n; ++j) {
            sum += costs[j];       // Add the cost of the current robot
            s.insert(times[j]);    // Insert the processing time of the current robot

            // If the budget is exceeded, adjust the window
            if (*rbegin(s) + sum * (j - i + 1) > budget) {
                sum -= costs[i];   // Remove the cost of the robot at index `i`
                s.erase(s.find(times[i])); // Remove the processing time of the robot at index `i`
                ++i;               // Shrink the window from the left
            }

            // Calculate the maximum length of the valid subarray at each step
            maxLength = max(maxLength, (int)(j - i + 1));
        }

        return maxLength; // Return the maximum length
    }
};
