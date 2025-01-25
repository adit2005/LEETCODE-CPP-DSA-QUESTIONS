class Solution {
public:
    vector<int> z(string& s) {
        vector<int> z(s.size());
        int l = 0, r = 1;
        for (int i = 1; i < s.size(); ++i) {
            z[i] = i > r ? 0 : min(r - i, z[i - l]);
            while (i + z[i] < s.size() && s[z[i]] == s[z[i] + i])
                ++z[i];
            if (z[i] + i > r) {
                l = i;
                r = z[i] + i;
            }
        }
        return z;
    }
    long long sumScores(string s) {
        vector<int> cnt = z(s);
        return accumulate(begin(cnt), end(cnt), 0LL) + s.size();
    }
};