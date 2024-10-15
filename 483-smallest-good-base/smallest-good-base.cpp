#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution 
{
public:
    string smallestGoodBase(string n) 
    {
        long long x = stoll(n);
        for (int m = log2(x) + 1; m >= 2; --m) 
        {
            long long left = 2, right = pow(x, 1.0 / (m - 1)) ;
            while (left < right) 
            {
                long long mid = left + (right - left) / 2;
                if (predicate(mid, m, x) == 0) 
                {
                    left = mid + 1;
                } 
                else 
                {
                    right = mid;
                }
            }
            if (predicate(left, m, x) == 1) 
            {
                return to_string(left);
            }
        }
        return to_string(x - 1);
    }

private:
    int predicate(long long base, int m, long long x) 
    {
        long long sum = 1, curr = 1;
        for (int i = 1; i < m; ++i) 
        {
            curr *= base;
            sum += curr;
            if (sum > x) return -1; // Indicating the sum has exceeded x
        }
        if (sum == x) return 1; // Indicating the sum is exactly x
        return 0; // Indicating the sum is less than x
    }
};