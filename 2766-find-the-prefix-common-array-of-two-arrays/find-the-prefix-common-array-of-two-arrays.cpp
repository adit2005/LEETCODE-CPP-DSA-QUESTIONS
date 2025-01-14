class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> s;
        vector<int> ans;
        for (int i = 0; i < A.size(); i++) {
            s.insert(A[i]);
            s.insert(B[i]);
            ans.push_back(2 * (i + 1) - s.size());
        }
        return ans;
    }
};