class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day, and if equal, by end day
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap for end times
        int res = 0; // Number of events attended
        int i = 0;   // Pointer to events
        int n = events.size();
        
        for (int day = 1; day <= 100000; ++day) {
            // Remove events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // Add all events starting today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                ++i;
            }
            
            // Attend the event that ends the earliest
            if (!pq.empty()) {
                pq.pop();
                ++res;
            }
        }
        
        return res;
    }
};
