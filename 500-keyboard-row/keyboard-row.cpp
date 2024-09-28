class Solution {
public:
    vector<string> findWords(vector<string>& a) {
        int n = (int)a.size();
        unordered_set<char>s1 = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
	    unordered_set<char>s2 = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
	    unordered_set<char>s3 = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            bool c1 = true;
            bool c2 = true;
            bool c3 = true;
            for (int j = 0; j < (int)a[i].size(); j++) {

                if (s1.find(a[i][j]) == s1.end())
                    c1 = false;
                if (s2.find(a[i][j]) == s2.end())
                    c2 = false;
                if (s3.find(a[i][j]) == s3.end())
                    c3 = false;
            }
            if (c1 or c2 or c3)
                ans.push_back(a[i]);
        }
        return ans;
    }
};