class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1); // adjacency matrix
        vector<int>vis(n+1,false); // vector to mark nodes visited 
        queue<int>q;
        int ans=INT_MAX;
        for(auto& r: roads){
            int a=r[0],b=r[1],d=r[2]; // first city, second city, distance
            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
        }

        q.push(1); // push the 1st city and mark it visited
        vis[1]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // loop to push the nodes connected to current node in the queue (if not visited)
            for(auto& r: adj[node]){
               
                if(!vis[r.first]) {
                    q.push(r.first);
                    vis[r.first]=true;
                }

                 ans=min(ans,r.second);
            }
        }
        return ans;
    }
};