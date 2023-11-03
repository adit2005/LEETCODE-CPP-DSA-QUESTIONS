class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        
        int idx = 1, pos = 0;
        while( pos < target.size()){
            ans.push_back("Push");
            
            if(target[pos] == idx)
                pos++;
            else 
                ans.push_back("Pop");
            
            idx++;
        }
        
        return ans;
    }
};