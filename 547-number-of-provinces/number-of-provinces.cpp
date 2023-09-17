class Solution {
    private:
    void bfs(vector<vector<int>> &graph,vector<bool> &visited,int src){
    
    queue<int> qu;
    qu.push(src);

    while(qu.empty()==false){
        int p = qu.front();
        qu.pop();

        if(visited[p]==true){
            continue;
        }

        visited[p] = true;

        for(int i = 0; i<graph.size() ;i++){
            if(visited[i]==false and graph[p][i]==1){
                qu.push(i);
            }
        }

    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
    int cntr = 0;
    vector<bool> visited(isConnected.size() , false);

    for(int i = 0; i<isConnected.size();i++){
        if(visited[i]==false){
            bfs(isConnected,visited,i);
            cntr++;
        }
    }

    return cntr;
    }
};