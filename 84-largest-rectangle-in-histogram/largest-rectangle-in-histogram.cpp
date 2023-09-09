// This one is optimised solution.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = INT_MIN;
        int area_with_top = 0;
        int top = 0;
        int i = 0;
        int n = heights.size();
        stack<int> s;

        while (i < n) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i++);
            } else {
                top = s.top();
                s.pop();
                area_with_top = heights[top] * (s.empty() ? i : i - s.top() - 1);
                ans = max(ans, area_with_top);
            }
        }

        while (!s.empty()) {
            top = s.top();
            s.pop();
            area_with_top = heights[top] * (s.empty() ? i : i - s.top() - 1);
            ans = max(ans, area_with_top);
        }

        return ans;
    }
};
