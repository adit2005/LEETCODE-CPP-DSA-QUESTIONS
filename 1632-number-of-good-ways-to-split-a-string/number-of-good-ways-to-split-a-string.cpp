class Solution {
public:
    int numSplits(string s) {
        int n = s.size(), uniqR = 0, uniqL = 0;
        vector<int> right(26,0), left(26,0);
        for(char &ch : s){
            right[ch-'a']++;
            if(right[ch-'a'] == 1)
                uniqR++;
        }
        int ans = 0;
        for(char &ch : s)
        {
            left[ch-'a']++;
            if(left[ch-'a'] == 1)
                uniqL++;
            right[ch-'a']--;
            if(right[ch-'a'] == 0)
                uniqR--;
            if(uniqL==uniqR) ans++;
          
        }
        return ans;
    }
};