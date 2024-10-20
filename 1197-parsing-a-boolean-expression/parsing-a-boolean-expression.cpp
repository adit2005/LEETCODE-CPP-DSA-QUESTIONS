class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        // Traverse the entire expression
        for (char currChar : expression) {
            if (currChar == ')') {
                vector<char> values;

                // Gather all values inside the parentheses
                while (st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();  // Remove '('
                char op = st.top();
                st.pop();  // Remove the operator

                // Evaluate the subexpression and push the result back
                char result = evaluateSubExpr(op, values);
                st.push(result);
            } else if (currChar != ',') {
                st.push(currChar);  // Push non-comma characters into the stack
            }
        }

        // Final result is on the top of the stack
        return st.top() == 't';
    }

private:
    // Evaluates a subexpression based on the operator and list of values
    char evaluateSubExpr(char op, vector<char>& values) {
        if (op == '!') return values[0] == 't' ? 'f' : 't';

        // AND: return 'f' if any value is 'f', otherwise return 't'
        if (op == '&') {
            for (char value : values) {
                if (value == 'f') return 'f';
            }
            return 't';
        }

        // OR: return 't' if any value is 't', otherwise return 'f'
        if (op == '|') {
            for (char value : values) {
                if (value == 't') return 't';
            }
            return 'f';
        }

        return 'f';  // This point should never be reached
    }
};