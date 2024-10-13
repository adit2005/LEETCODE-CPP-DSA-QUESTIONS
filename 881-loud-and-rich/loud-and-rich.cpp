class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int m = quiet.size();
        vector<vector<int>>adj(m,vector<int>(m,0));
        vector<int>outDegree(m,0);
        for(auto &it:richer){
            adj[it[0]][it[1]]=1;
            outDegree[it[1]]++;
        }
        vector<int>ans(m,INT_MAX);
        queue<int>q;
        for(int i=0;i<m;++i){
            if(outDegree[i]==0){q.push(i);}
            ans[i]=i;
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<m;++i){
                if(adj[node][i]==1){
                    if(quiet[ans[node]]<quiet[ans[i]]){
                        ans[i]=ans[node];
                    }
                    outDegree[i]--;
                    if(outDegree[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }
};