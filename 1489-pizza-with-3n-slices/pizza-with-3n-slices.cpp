class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        vector<int> prev1(k+2,0);
        vector<int> curr1(k+2,0);
        vector<int> next1(k+2,0);
        
        vector<int> prev2(k+2,0);
        vector<int> curr2(k+2,0);
        vector<int> next2(k+2,0);


        for(int start = k-2; start >= 0; start--){
            for(int n = 1; n <= k/3; n++){
                int incl = slices[start] + next1[n-1];
                int excl = 0 + curr1[n];

                prev1[n] = max(incl,excl);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        for(int start = k-1; start >= 1; start--){
            for(int n = 1; n <= k/3; n++){
                int incl = slices[start] + next2[n-1];
                int excl = 0 + curr2[n];

                prev2[n] = max(incl,excl);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case1 = curr1[k/3];
        int case2 = curr2[k/3];
        return max(case1,case2);
    }
};