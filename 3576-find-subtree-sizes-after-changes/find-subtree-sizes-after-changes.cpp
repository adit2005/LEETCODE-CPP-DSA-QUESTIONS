class Solution {
public:

    int dfs(int i, string &s, vector<int>&ans, unordered_map<char,stack<int>>&mp, vector<int>adj[]){
        int count=1;  //counting self
        mp[s[i]].push(i); 
        for(auto &j:adj[i]){
            count+=dfs(j,s,ans,mp,adj);
        }
        ans[i]+=count;  //Increment the answer
        mp[s[i]].pop(); 

        //If there exist some node of the same character
        //give the answer to that node (add the edge condition)
        //and give nothing to current parent (break edge condition)
        if(!mp[s[i]].empty()){
            
            ans[mp[s[i]].top()]+=ans[i];  
            
            return 0; 
        }
        //else give the answer to current parent (do nothing condition)
        return ans[i];

    }

    vector<int> findSubtreeSizes(vector<int>& par, string s) {
        int n=s.size();
        vector<int>adj[n+1];
        for(int i=1;i<n;i++){
            adj[par[i]].push_back(i);
        }
        vector<int>ans(n,0);
        unordered_map<char,stack<int>>mp;
        dfs(0,s,ans,mp,adj);
        return ans;
    }
};