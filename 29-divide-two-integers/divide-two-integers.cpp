class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long dd = abs(static_cast<long long>(dividend)); // Cast to long long to handle INT_MIN
        long long dv = abs(static_cast<long long>(divisor)); // Cast to long long to handle INT_MIN

        long long res = 0;
        while (dd >= dv) {
            long long temp = dv, multiple = 1;
            while (dd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dd -= temp;
            res += multiple;
        }

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            return -res;
        else
            return res;
    }
};
