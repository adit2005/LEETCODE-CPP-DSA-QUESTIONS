class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        long long all_sum = accumulate(shifts.begin(), shifts.end(), 0LL);
        int n = s.size(), shift;
        for(int i=0;i<n;i++)
        {
            shift = all_sum%26;
            s[i] = (s[i]-'a'+shift)%26+'a';
            all_sum -= shifts[i];
        }
        return s;
    }
};