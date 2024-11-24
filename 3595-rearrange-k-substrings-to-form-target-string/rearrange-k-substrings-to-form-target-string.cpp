class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        if (s.size() % k != 0) return false; // Ensure k equal-sized substrings
        int sub_len = s.size() / k;

        // Count substrings of size sub_len in t
        unordered_map<string, int> t_count;
        for (int i = 0; i < t.size(); i += sub_len) {
            t_count[t.substr(i, sub_len)]++;
        }

        // Count substrings of size sub_len in s
        unordered_map<string, int> s_count;
        for (int i = 0; i < s.size(); i += sub_len) {
            s_count[s.substr(i, sub_len)]++;
        }

        // Check if both counts match
        return s_count == t_count;
    }
};
