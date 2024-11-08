class Solution {
public:
    // Global variable to track the current time
    int currentTime = 0;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        // Directions for moving up, down, left, right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        // Priority queue to store rooms based on the minimum time to reach them
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        // Vector to store the minimum time to reach each room
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        
        // Start from the (0, 0) room at time t = 0
        pq.push({0, 0, 0});  // {time, x, y}
        time[0][0] = 0;
        
        while (!pq.empty()) {
            // Extract the current room's time and coordinates
            auto [extractedTime, x, y] = pq.top();  
            pq.pop();
            
            // Set currentTime to the extracted value
            currentTime = extractedTime;
            
            // If we've reached the bottom-right room, return the time taken to reach it
            if (x == n - 1 && y == m - 1) {
                return currentTime;
            }
            
            // Check the 4 possible adjacent rooms
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Skip if the new position is out of bounds
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                
                // Calculate the new time based on the moveTime of the neighbor
                int newTime = currentTime + 1; // Start with +1 for moving
                
                // Add the neighbor's move time only if it's larger than the current time
                if (moveTime[nx][ny] > currentTime) {
                    newTime = newTime + (moveTime[nx][ny]-currentTime);
                }
                
                // If the new time is better, update it and push to the priority queue
                if (newTime < time[nx][ny]) {
                    time[nx][ny] = newTime;
                    pq.push({newTime, nx, ny});
                }
            }
        }
        
        return -1;  // In case there is no way to reach the bottom-right room
    }
};
