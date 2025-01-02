class Solution {
public:
   vector<int> prevPermOpt1(vector<int>& A) {
        int i = A.size() - 2, max_ = -1;
        while(i >= 0 && A[i] <= A[i+1])
            --i;
        if(i >= 0){
            max_ = i + 1;
            for(int j = max_ + 1; j < A.size(); ++j)
                if(A[max_] < A[j] && A[j] < A[i])
                    max_ = j;
           
        }
         if(i>=0){
            swap(A[max_], A[i]);
         }
        return A;
    }
};