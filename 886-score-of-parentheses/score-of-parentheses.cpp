class Solution {
public:
    int scoreOfParentheses(string s){
        stack<int> stack;
        int currentScore = 0;
        for(auto&c : s){
            if(c == '('){
                // Push the current score and reset it
                stack.push(currentScore);
                currentScore = 0;
            } else {// 1 means we onlly have one pair of ( ) , 2 means so far we are (())
                // Pop the last score and add the max of 1 or 2 * currentScore
                int lastScore = stack.top();
                stack.pop();
                currentScore = lastScore + max(1, 2 * currentScore);
            }
        }
        return currentScore;
    }
};