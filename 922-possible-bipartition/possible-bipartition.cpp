class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        if(dislikes.empty()) return true;
        
        unordered_map<int,vector<int>> g;
        for(vector<int>&a: dislikes){
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);

        }

        vector<int> cols(1+n, -1);
        queue<int> q;
    
        bool ans = true;

        //we will recursively go through the loop because disjoint components may occur
        int i = 1;
        while(i <= n){
            if(cols[i]==-1){
                q.push(i);
                cols[i] = 1; // initializing the colour of first element with 1
                ans &= checkbfs(cols, g, q);
            }
            i++;
        }
        return ans;
    }
    bool checkbfs(vector<int> &cols, unordered_map<int,vector<int>> &g, queue<int> &q){
    
        int curr=1;
        while(!q.empty()){

            int size = q.size();

            for(int k = 0;k<size; k++){

                vector<int> &a = g[q.front()];
                q.pop();
                for(int i: a){
                    
                    if(cols[i]!=-1){
                        if(cols[i]==abs(curr-1)){
                            //its okay
                            continue;
                        }
                        else{
                            return false;
                        }
                    }else{
                        cols[i] = abs(curr-1);
                        q.push(i);
                    }
                }
            }
            curr  = abs(curr-1);
        }
    return true;
    }
};