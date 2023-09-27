class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        return calc(1, 1, 1, n);
    }
    int calc(int step, int val, int copy, int n)
    {
        if (step > n || val > n)
            return INT_MAX;
        if (val == n)
            return step;
        return min(calc(step + 1, val + copy, copy, n), calc(step + 2, 2 * val, val, n));
    }
};