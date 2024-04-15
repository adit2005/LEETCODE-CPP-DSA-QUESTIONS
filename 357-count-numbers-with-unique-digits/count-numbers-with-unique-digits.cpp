class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        long long prevFactorial, curFactorial;
        vector<vector<int>> nCk(11, vector<int>(11));
        int dpOneBack;

        dpOneBack = 1;
        curFactorial = 1;
        nCk[0][0] = 1;

        for (int i = 1; i < 11; ++i){
            for (int k = 0; k <= i; ++k){
                nCk[i][k] = ((k == 0 || k >= i) ? 1 : nCk[i - 1][k - 1] + nCk[i - 1][k]);
            }
        }
        
        for (int i = 1; i <= n; ++i)
        {
            prevFactorial = curFactorial;
            curFactorial = i * prevFactorial;
            dpOneBack = (((curFactorial * nCk[10][i]) - (prevFactorial * nCk[9][i - 1])) + dpOneBack);
        }

        return dpOneBack;
    }
};
