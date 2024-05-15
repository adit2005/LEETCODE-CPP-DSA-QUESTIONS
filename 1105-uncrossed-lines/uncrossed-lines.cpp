class Solution {
public:
    
    int m, n;
    
    int t[501][501];
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        
        if(i >= m || j >= n) {
            return 0;
        }
        
        if(t[i][j] != -1) {
            return t[i][j];
        }
        
        if(nums1[i] == nums2[j]) {
            
            return t[i][j] = 1 + solve(i+1, j+1, nums1, nums2);
            
        } else {
            
            int fix_i = solve(i, j+1, nums1, nums2);
            int fix_j = solve(i+1, j, nums1, nums2);
            
            return t[i][j] = max(fix_i, fix_j);
            
        }
        
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(0, 0, nums1, nums2);
    }
};