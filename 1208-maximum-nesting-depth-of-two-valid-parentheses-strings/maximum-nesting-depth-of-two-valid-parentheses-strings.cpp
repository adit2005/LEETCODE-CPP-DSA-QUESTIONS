class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size(); // Length of the input string
        vector<int> answer(n, 0); // Initialize the answer vector with 0s

        stack<pair<int, int>> st; // Stack to store pairs (depth, index)

        // Iterate through each character in the input string
        for(int i = 0; i < n; i++) {
            if(seq[i] == '(') {
                // If the current character is an opening parenthesis
                if(!st.empty()) {
                    // If the stack is not empty, determine the depth for this '('
                    // Alternate the depth: if top element's depth is 0, push 1; otherwise, push 0
                    st.push({st.top().first == 0 ? 1 : 0, i});
                } else {
                    // If the stack is empty (first opening parenthesis), start with depth 0
                    st.push({0, i});
                }
            } else {
                // If the current character is a closing parenthesis
                auto [cnt, idx] = st.top(); // Get the depth and index from the top of the stack
                st.pop(); // Remove the top element from the stack
                answer[idx] = cnt; // Assign the depth to the index of the matching opening parenthesis
                answer[i] = cnt; // Assign the depth to the current closing parenthesis
            }
        }

        return answer; // Return the answer vector
    }
};
