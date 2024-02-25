class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> m;
        vector<int> indegree(n,0);
        for(auto it :pre)
        {
            m[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: m[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        return topo.size()==n?1:0;
    }
};