class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Create a 2D array to represent the champagne distribution in glasses,
        // initialize all elements to 0.0.
        double result[101][101] = {0.0};
        
        // Pour the initial amount of champagne into the top glass (row 0, glass 0).
        result[0][0] = poured;
        
        // Iterate through each row of glasses up to the 100th row.
        for (int i = 0; i < 100; i++) {
            // Iterate through the glasses in the current row (up to i).
            for (int j = 0; j <= i; j++) {
                // If the current glass has champagne overflowing (more than or equal to 1 unit),
                if (result[i][j] >= 1) {
                    // Calculate the overflow and distribute it equally to the glasses below.
                    result[i + 1][j] += (result[i][j] - 1) / 2.0;
                    result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
                    
                    // Set the current glass to have exactly 1 unit of champagne.
                    result[i][j] = 1;
                }
            }
        }
        
        // Return the amount of champagne in the specified glass (query_row, query_glass).
        return result[query_row][query_glass];
    }
};
