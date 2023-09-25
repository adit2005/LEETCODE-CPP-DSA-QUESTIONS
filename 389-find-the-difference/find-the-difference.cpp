class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(char it: s) c ^= it;
        for(char is: t) c ^= is;
        return c;
    }
};