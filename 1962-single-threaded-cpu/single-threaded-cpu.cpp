class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // Add original indices to tasks
        vector<array<int, 3>> sortedTasks;
        for (int i = 0; i < n; i++) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i}); // {enqueueTime, processingTime, index}
        }
        // Sort tasks by enqueue time
        sort(sortedTasks.begin(), sortedTasks.end());

        // Min-heap to store tasks {processingTime, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<int> result;
        long long time = 0; // Current time
        int i = 0;          // Pointer to sortedTasks

        while (i < n || !pq.empty()) {
            // Push all tasks whose enqueueTime <= time into the heap
            while (i < n && sortedTasks[i][0] <= time) {
                pq.push({sortedTasks[i][1], sortedTasks[i][2]}); // {processingTime, index}
                i++;
            }

            if (!pq.empty()) {
                // Process the task with the shortest processing time (or smallest index)
                auto [processingTime, index] = pq.top();
                pq.pop();
                time += processingTime; // Increment time by the processing time of the task
                result.push_back(index);
            } else {
                // If no tasks are available, move time to the next task's enqueue time
                time = sortedTasks[i][0];
            }
        }

        return result;
    }
};
