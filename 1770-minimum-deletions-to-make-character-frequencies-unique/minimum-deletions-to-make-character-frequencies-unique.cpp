class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> cnt;
        int deletions = 0;
        unordered_set<int> used_freq;

        for(char c : s){
            cnt[c]++;
        }

        for(auto & it : cnt){
            int freq = it.second;
            while(freq> 0 && used_freq.find(freq) != used_freq.end()){
                freq--;
                deletions++;
            }
            used_freq.insert(freq);

        }

        return deletions;
        
    }
};