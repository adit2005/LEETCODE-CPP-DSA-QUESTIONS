class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Create a max heap (priority queue) to store character frequencies.
        priority_queue<pair<int, char>> pq;
        string ans = ""; // Initialize the result string.

        // Add characters with their counts to the priority queue if their counts are greater than 0.
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        // Continue until the priority queue is empty.
        while (!pq.empty()) {
            // Get the character with the highest frequency.
            int f1 = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            // If the last character added to the result is not the same as the current character.
            if (ans.size() > 0 && ans.back() != ch) {
                // Add up to 2 occurrences of the current character to the result string.
                int tmp = min(2, f1);
                for (int j = 0; j < tmp; j++)
                    ans += ch;
                f1 -= tmp;
            }
            // If the result string is empty, we can start by adding up to 2 occurrences.
            else if (ans.size() == 0) {
                int tmp = min(2, f1);
                for (int j = 0; j < tmp; j++)
                    ans += ch;
                f1 -= tmp;
            }
            // If the last character in the result is the same as the current character.
            else {
                // If there are no other characters left, we cannot add the current character to avoid repetition.
                if (pq.size() == 0)
                    break;

                // Get the character with the second highest frequency.
                int f2 = pq.top().first;
                char c = pq.top().second;
                pq.pop();

                // Add one occurrence of this character to the result string.
                ans += c;
                f2--;

                // If there are still occurrences left, push it back to the priority queue.
                if (f2 > 0)
                    pq.push({f2, c});
            }

            // If there are still occurrences of the current character left, push it back to the priority queue.
            if (f1 > 0)
                pq.push({f1, ch});
        }

        return ans;
    }
};
