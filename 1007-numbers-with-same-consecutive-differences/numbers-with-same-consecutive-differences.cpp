class Solution {
public:
    void dfs(vector<int>& ans, int N, int& K, int num){
        if(N==0){
            ans.push_back(num);
            return ;
        }
        int digit = num%10;
        if(digit + K <=9){
            dfs(ans, N-1, K, num*10 + digit + K);            
        }
        // K!=0 is considered, as when K=0 then the above if condition produces same solution as the below condition. (Ex: N=2, K=0)
        if(digit - K >=0 && K!=0){
            dfs(ans, N-1, K, num*10 + digit - K);            
        }
       
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        
        vector<int> ans;
        if(N==1) ans.push_back(0);
		// First digit will never be 0 except when N=1.
        for(int i=1;i<=9;i++){
            dfs(ans, N-1, K, i);
        }
        return ans;
        
    }
};