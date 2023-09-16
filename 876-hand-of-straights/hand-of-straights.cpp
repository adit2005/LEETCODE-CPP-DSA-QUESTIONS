class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Check if the total number of cards is not divisible by groupSize
        if (hand.size() % groupSize != 0)
            return false;

        int curr = 0;     // Counter for the current group
        int prev = -1;    // Previous card value (initialized to -1)
        
        // Create a min-heap (priority queue) to efficiently track the cards
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Initialize the min-heap with the cards from the input vector
        for (auto h : hand)
            pq.push(h);

        vector<int> tmp;  // Temporary vector to hold cards that cannot be added to the current group

        while (!pq.empty()) {
            int t = pq.top();  // Get the smallest card from the min-heap
            pq.pop();

            // Only add the card to the current group if it's a new group or the next number is consecutive
            if (prev == -1 || t - prev == 1) {
                prev = t;
                curr++;
            } else {
                // Save all cards that cannot be added to the current group
                // These will be pushed back into the min-heap once a new group starts
                tmp.push_back(t);
            }

            // If the current group is complete (groupSize cards), reset counters and push back unadded cards
            if (curr == groupSize) {
                curr = 0;
                prev = -1;

                for (auto e : tmp)
                    pq.push(e);

                tmp = {};  // Clear the temporary vector
            }
        }

        // If a group is incomplete (curr > 0), return false; otherwise, return true
        return curr>0 ? false : true;
    }
};
