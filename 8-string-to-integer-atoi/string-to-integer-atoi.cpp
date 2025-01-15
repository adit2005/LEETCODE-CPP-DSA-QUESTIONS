#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoiRecursive(string &s, int i, int sign, int num) {
        // Base case: If the index goes out of bounds or the character is non-digit
        if (i >= s.size() || !isdigit(s[i])) {
            return num * sign;
        }

        // Overflow handling
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }

        // Convert current character to integer and update `num`
        num = num * 10 + (s[i] - '0');

        // Recursive call for the next character
        return myAtoiRecursive(s, i + 1, sign, num);
    }

    int myAtoi(string s) {
        int i = 0, num = 0, sign = 1;

        // Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') i++;

        // Handle sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Start recursion to process digits
        return myAtoiRecursive(s, i, sign, num);
    }
};
