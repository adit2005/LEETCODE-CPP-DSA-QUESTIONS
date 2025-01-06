class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<int> stack; // To store indices of cars
        vector<double> res(n, -1); // Initialize result with -1 (no collision)

        // Traverse from the last car to the first car
        for (int i = n - 1; i >= 0; --i) {
            int p = cars[i][0], s = cars[i][1]; // Current car's position and speed

            // Remove cars from the stack that are irrelevant for collision
            while (!stack.empty()) {
                int j = stack.back(); // Index of the top car in the stack
                int p2 = cars[j][0], s2 = cars[j][1]; // Position and speed of the car in the stack

                // Check if the current car can ever collide with the car in the stack
                // (1) Current car is slower or at the same speed as the stack car: No collision
                // (2) The collision time with this stack car is larger than its existing collision time
                if (s <= s2 || (res[j] > 0 && 1.0 * (p2 - p) / (s - s2) > res[j])) {
                    stack.pop_back(); // Remove the irrelevant car
                } else {
                    break; // Keep this car in the stack
                }
            }

            // Calculate the collision time with the top car in the stack (if any)
            if (!stack.empty()) {
                int j = stack.back();
                res[i] = 1.0 * (cars[j][0] - p) / (s - cars[j][1]);
            }

            // Add the current car to the stack
            stack.push_back(i);
        }

        return res;
    }
};
