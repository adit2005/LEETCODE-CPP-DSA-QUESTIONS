class Solution {
public:
    // Function to perform arithmetic operations
    int perform(int x, int y, char op) {
        if (op == '+') return x + y;
        if (op == '-') return x - y;
        if (op == '*') return x * y;
        return 0;
    }
    
    // Recursive function to compute different ways to evaluate the expression
    vector<int> diffWaysToCompute(string exp) {
        vector<int> results;  // Store the results
        
        bool isNumber = true;  // Flag to check if the expression is a number
        
        // Loop through the expression
        for (int i = 0; i < exp.length(); i++) {
            // Check if the current character is an operator
            if (!isdigit(exp[i])) {
                isNumber = false;  // The expression is not purely a number
                
                // Split the expression into two parts: left and right operands
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));
                
                // Combine left and right operands with the operator and store the results
                for (int x : left) {
                    for (int y : right) {
                        int val = perform(x, y, exp[i]);
                        results.push_back(val);
                    }
                }
            }
        }
        
        // If the expression is a pure number, convert it to integer and add it to results
        if (isNumber) {
            results.push_back(stoi(exp));
        }
        
        return results;
    }
};
