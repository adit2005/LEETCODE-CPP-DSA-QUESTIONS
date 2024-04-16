class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            int l = words[i].size();
            string a = words[i];
            int curr = -1;

            for (int j = 0; j < l; j++) {
                auto it = upper_bound(mp[a[j]].begin(), mp[a[j]].end(), curr);
                if (it == mp[a[j]].end()) break;
                curr = *it;
                if (j == l - 1) count++;
            }
        }
        return count;
    }
};