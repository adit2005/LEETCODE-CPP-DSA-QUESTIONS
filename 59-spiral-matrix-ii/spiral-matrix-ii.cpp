class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int top = 0;
        int left = 0;
        int bottom = n-1;
        int right = n-1;
        int  k =1;

        while(top <= bottom && left <= right){
            // traversing right
            for(int i = left; i <= right; i++){
                matrix[top][i] = k;
                k++;
            }
            top++;

            //traversing down
            for(int i = top; i<= bottom; i++){
                matrix[i][right] = k;
                k++;
            }
            right--;
            
            //traversing left
            if(top <= bottom){
                for(int i = right; i>= left; i--){
                    matrix[bottom][i] = k;
                    k++;
                }
                bottom--;
            }

            //traversing up
            if(left <= right){
                for(int i = bottom; i>= top; i--){
                    matrix[i][left] = k;
                    k++;
                }
                left++;
            }

        }

        return matrix;
        
    }
};