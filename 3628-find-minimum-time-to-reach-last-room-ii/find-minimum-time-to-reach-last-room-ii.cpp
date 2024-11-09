class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        // Directions for moving up, down, left, right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        // Priority queue to store rooms based on the minimum time to reach them
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        
        // Vector to store the minimum time to reach each room
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        
        // Start from the (0, 0) room at time t = 0 and initial step cost 1
        pq.push({0, 0, 0, 1});  // {time, x, y, stepCost}
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [extractedTime, x, y, stepCost] = pq.top();  
            pq.pop();
            
            // If we've reached the bottom-right room, return the time taken to reach it
            if (x == n - 1 && y == m - 1) {
                return extractedTime;
            }
            
            // Toggle step cost for the next move
            int nextStepCost = (stepCost == 1) ? 2 : 1;
            
            // Check the 4 possible adjacent rooms
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Skip if the new position is out of bounds
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                
                // Calculate the new time based on the moveTime of the neighbor and step cost
                int newTime = extractedTime + stepCost;
                
                // Wait if the room's move time is greater than the calculated new time
                if (moveTime[nx][ny] > extractedTime) {
                    newTime = newTime + (moveTime[nx][ny] - extractedTime);
                }
                
                // If the new time is better, update it and push to the priority queue
                if (newTime < time[nx][ny]) {
                    time[nx][ny] = newTime;
                    pq.push({newTime, nx, ny, nextStepCost});
                }
            }
        }
        
        return -1;  // In case there is no way to reach the bottom-right room
    }
};
