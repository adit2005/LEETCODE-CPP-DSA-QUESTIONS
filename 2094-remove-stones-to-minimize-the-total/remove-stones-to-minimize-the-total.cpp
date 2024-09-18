class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        
        priority_queue<int> pq;

        for(auto &i : piles) {
            pq.push(i);
        }

        while(k--) {
            int curr = pq.top();
            pq.pop();

            pq.push(curr - floor(curr/2));
        }

        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }


        return sum;
    }
};