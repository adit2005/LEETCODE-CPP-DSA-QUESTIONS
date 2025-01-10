class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    int ans = 0, j = -1;
    long long s = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < runningCosts.size(); i++) {
        s += runningCosts[i];
        pq.push(make_pair(chargeTimes[i], i));
        while (s * (i - j) + 1LL * removeStale(pq, j) > budget)
            s -= runningCosts[++j];
        ans = max(ans, i - j);
    }
    return ans;
}
int removeStale(priority_queue<pair<int, int>>& pq, int& j) {
    while (!pq.empty() && pq.top().second <= j) pq.pop();
    if (pq.empty()) return 0;
    return pq.top().first;
}
};