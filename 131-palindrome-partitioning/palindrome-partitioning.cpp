class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) return res;

        vector<string> part;
        dfs(0, s, part, res);

        return res;
        
    }


    void dfs(int index, string &s, vector<string> &part, vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(part);
            return;
        }

        for(int i =index; i< s.size(); i++){
            if(isPalindrome(s, index, i)){
                part.push_back(s.substr(index, i-index+1));
                dfs(i+1, s, part, res);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--])
              return false;
        }

        return true;
    }
};