class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (matchsticks.size() < 4 || sum % 4) return false;
        
        int target = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); // Sort in descending order to place larger sticks first
        vector<int> sides(4, 0); // To keep track of each side's length
        
        return backtrack(matchsticks, sides, 0, target);
    }
    
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        if (index == matchsticks.size()) {
            // Check if all four sides are equal to the target length
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }
        
        for (int i = 0; i < 4; i++) {
            // Try adding the current matchstick to each side
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                
                if (backtrack(matchsticks, sides, index + 1, target)) return true;
                
                sides[i] -= matchsticks[index];
            }
            
            // If the current side is 0, then adding the stick to any other empty side would result in the same outcome.
            //if (sides[i] == 0) break;
        }
        
        return false;
    }
};
