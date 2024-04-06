class Solution {
public:
    // Recursive helper function to find the winner
    int helper(int n, int k) {
        // Base case: if there's only one person left, they are the winner (index 1-based)
        if (n == 1)
            return 1;
        
        // Calculate the position of the next person to be eliminated using modulo operation
        // The next person's position is (current_position + k - 1) % n + 1
        // Subtract 1 from k to adjust for 1-based indexing, and add 1 at the end for 1-based indexing
        return (helper(n - 1, k) + k - 1) % n + 1;
    }
    
    // Function to find the winner's index (1-based)
    int findTheWinner(int n, int k) {
        // Return the result of helper function
        return helper(n, k);   
    }
};
