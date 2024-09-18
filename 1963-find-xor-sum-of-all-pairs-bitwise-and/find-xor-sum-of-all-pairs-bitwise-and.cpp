class Solution {
public:
        int getXORSum(vector<int>& A, vector<int>& B) {
        int xora = 0, xorb = 0;
        for (int& a: A)
            xora ^= a;
        for (int& b: B)
            xorb ^= b;
        return xora & xorb;
    }
};