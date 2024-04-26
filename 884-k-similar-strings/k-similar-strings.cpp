class Solution {  
public:
    map<string, int> mp;
    int solve(string &s1, string &s2, int i, int n) {
        if(i == n) {
            return 0;
        }
        if(mp.find(s1) != mp.end()) {
            return mp[s1];
        }
        if(s1[i] == s2[i]) {
            return mp[s1] = (solve(s1, s2, i + 1, n));
        }
        int ans = 100;
        for(int k = i; k < n; ++k) {
            if(s1[k] == s2[i]) {
                swap(s1[i], s1[k]);
                int steps = 1 +solve(s1, s2, i + 1, n);
                ans = min(ans, steps);
                swap(s1[i], s1[k]);
            }
        }
         mp[s1] = ans;
        return ans;
    }

    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        return solve(s1, s2, 0, n);
    }
};