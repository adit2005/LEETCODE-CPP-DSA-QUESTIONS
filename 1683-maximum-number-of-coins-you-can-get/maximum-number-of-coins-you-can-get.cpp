class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int sum=0;
        int pair= piles.size()/3;
        for(int i=pair;i<piles.size();i+=2)
        {
            sum+=piles[i];
        }
        return sum;
    }
};