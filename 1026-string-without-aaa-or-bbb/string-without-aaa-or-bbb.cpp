class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string result = "";
        while (a > 0 || b > 0) {
            if (result.size() >= 2 && result.back() == result[result.size() - 2]) {
                // If the last two characters are the same, append the other character
                if (result.back() == 'a' && b > 0) {
                    result += 'b';
                    b--;
                } else if (a > 0) {
                    result += 'a';
                    a--;
                }
            } else {
                // Otherwise, append the character with more remaining occurrences
                if (a >= b && a > 0) {
                    result += 'a';
                    a--;
                } else if (b > 0) {
                    result += 'b';
                    b--;
                }
            }
        }
        return result;
    }
};
