class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;

        int count_1 = 0;
        int count_0 = 0;

        while(n){
            if((n&1) == 1) count_1 ++;
            else count_0++;
            n = n>>1;

        }

        if(count_1 == 1 && count_0 % 2 == 0) return true;
        else return false;
    }
};