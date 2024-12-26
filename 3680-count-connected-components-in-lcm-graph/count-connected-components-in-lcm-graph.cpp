class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &vis){
        vis[node]=1;


        for(auto i:adj[node]){
            if(vis[i]==0){
                dfs(i,adj,vis);
            }
        }
    }
    int countComponents(vector<int>& nums, int threshold) {
        int n=nums.size();

        unordered_map<int,vector<int>> adj;
        for(auto i:nums){
           for(auto j=2*i;j<=threshold;j+=i){
            adj[i].push_back(j);
            adj[j].push_back(i);
           }
        }

        unordered_map<int,bool> vis;
        int ans=0;

        for(int i:nums){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }

        return ans;
    }
};