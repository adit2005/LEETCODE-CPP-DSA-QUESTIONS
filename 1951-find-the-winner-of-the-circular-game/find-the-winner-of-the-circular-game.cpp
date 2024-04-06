class Solution {
public:
    
    int findTheWinner(int n, int k) {
        int winner = 0; 
        
        for (int i = 1; i <= n; ++i) {
            winner = (winner + k - 1) % i + 1;
        }
        
        return winner;
    }
};
