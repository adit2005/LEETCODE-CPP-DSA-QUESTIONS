class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<int> t;
        for (char c : s) {
            if (c == '(') {
                if (t.empty() || t.top() == 2) t.push(2);
                else {
                    t.pop();
                    t.push(2);
                    ans++;
                }
            }
            else {
                if (t.empty()) {
                    t.push(1); ans++;
                } else if (t.top() == 1) {
                    t.pop();
                } else if (t.top() == 2) {
                    t.pop(); t.push(1);
                }
            }
        }
        while (!t.empty()) {
            ans += t.top();
            t.pop();
        }
        return ans;
    }
};