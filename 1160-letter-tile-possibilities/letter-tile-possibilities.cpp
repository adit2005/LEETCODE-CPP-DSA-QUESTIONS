class Solution {
public:
    void backtrack(string tiles,vector<bool> &visited,int &count)
    {
        for(int i=0;i<tiles.size();i++)
        {
            if(visited[i] || i>0 && tiles[i]==tiles[i-1] && visited[i-1]==false)
                continue;
            visited[i]=true;
            count++;
            backtrack(tiles,visited,count);
            visited[i]=false;
        }
    }
    int numTilePossibilities(string tiles) {
        int count=0;
        int n=tiles.size();
        sort(tiles.begin(),tiles.end());
        vector<bool> visited(n,false);
        backtrack(tiles,visited,count);
        return count;
    }
};