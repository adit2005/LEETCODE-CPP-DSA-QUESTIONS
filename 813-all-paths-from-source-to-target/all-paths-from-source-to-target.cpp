class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int s=0;
        int n=graph.size()-1;
        vector<int>path;
        path.push_back(s);
        vector<vector<int>>ans;
        queue<vector<int>>q;
        q.push(path);
        while(!q.empty()){
            path=q.front();
            q.pop();
            int val=path.back();
            if(val==n){
                ans.push_back(path);
            }
            for(int &i:graph[val]){
                vector<int>v(path);
                v.push_back(i);
                q.push(v);
            }
        }
        return ans;
    }
};