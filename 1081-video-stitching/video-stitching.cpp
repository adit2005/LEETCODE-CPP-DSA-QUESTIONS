class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (clips.size()==0)
            return -1;
        
        vector<int> jumps(T, 0);
        
        for (auto c : clips)
            if (c[0]<T)
                jumps[c[0]] = max(jumps[c[0]], c[1]);
        
        int ans = 0, i, farthest, end;
        
        for (i=0, farthest=0, end=0; i<jumps.size(); i++) {
            if (end<i)
                return -1;
                
            farthest = max(farthest, jumps[i]);
            
            if (end==i) {
                end = farthest;
                ans++;
            }
        }
        
        return end>=T ? ans : -1;
    }
};