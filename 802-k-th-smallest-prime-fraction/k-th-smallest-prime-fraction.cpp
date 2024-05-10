class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> minHeap;
        int N = arr.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                minHeap.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }
        
        pair<int, int> result;
        for (int i = 0; i < k; ++i) {
            result = minHeap.top().second;
            minHeap.pop();
        }
        
        return {result.first, result.second};
    }
};