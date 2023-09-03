class Solution {
public:
    vector<int> set_diff(vector<int>& n1, vector<int>& n2){
        vector<int> S1_minus_S2;
        unordered_set<int> S1(n1.begin(), n1.end());
        unordered_set<int> S2(n2.begin(), n2.end());
        for(int y: S1)
            if (S2.find(y)==S2.end()) S1_minus_S2.push_back(y);
        return S1_minus_S2;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {set_diff(nums1, nums2), set_diff(nums2, nums1)};
    }
};