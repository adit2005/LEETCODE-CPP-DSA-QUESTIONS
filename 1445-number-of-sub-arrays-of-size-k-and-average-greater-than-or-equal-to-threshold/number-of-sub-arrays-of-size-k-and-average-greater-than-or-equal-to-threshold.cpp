class Solution {
public:
    int numOfSubarrays(vector<int>& v, int k, int threshold) {
        int left = 0;
        int sum = 0;
        int ans = 0;
        threshold *= k;
        for (int right = 0; right < v.size(); right++) {
            sum += v[right];
            if (right >= k) {
                sum -= v[left++];
            }
            if (sum >= threshold && right - left + 1 == k)
                ans += 1;
        }
        return ans;
    }
};