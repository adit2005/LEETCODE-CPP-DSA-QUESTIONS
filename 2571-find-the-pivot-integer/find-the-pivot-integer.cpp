class Solution {
public:
    int getSum(int x) {
        return x * (x + 1) / 2;
    }

    int pivotInteger(int n) {
        int sum = getSum(n);

        int l = 1;
        int r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int firstPart = getSum(m);
            int secondPart = sum - firstPart + m; 
            
            if (firstPart == secondPart)
                return m;
            else if (firstPart > secondPart)
                r = m - 1;
            else
                l = m + 1;
        }

        return -1;
    }
};