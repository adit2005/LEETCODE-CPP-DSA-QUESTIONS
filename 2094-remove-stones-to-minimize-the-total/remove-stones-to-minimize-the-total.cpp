// Using Buckets - TC = O(n + k) && SC = O(1)
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int freq[10001] = {0};
        int ans = 0;
        for(int pile: piles) {
            ans += pile;
            freq[pile]++;
        }
        for(int i = 10000; i > 1 && k > 0; i--) {
            if(freq[i] > 0) {
                int canTake = min(freq[i], k);
                k -= canTake;
                
                freq[i - i / 2] += canTake;
                ans -= canTake * (i / 2);
            }
        }
        return ans;
    }
};