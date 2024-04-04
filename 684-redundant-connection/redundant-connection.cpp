class Solution {
public:
    vector<int> parents;
    int find_parent(int a){
        if(parents[a] == a){
            return a;
        } else {
            return parents[a] = find_parent(parents[a]);    //Finding parents using path compression
        }
    }
    void do_union(int node1 , int node2){   
        node1 = find_parent(node1);
        node2 = find_parent(node2);
        if(node1 == node2){     // If they have same parents, do nothing
            return;
        } else {                //Else, connect node1 to node2 by assigning the parent of node1 to node2
            parents[node2] = node1;
            return;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parents = vector<int>(1001);
        for(int i = 0 ; i < 1001 ; ++i){    //Self initializing the parents, because every node is disconnected at first.
            parents[i] = i;
        }
        vector<int> answer(2 , 0);
        for(int i = 0 ; i < edges.size() ; ++i){
            if(find_parent(edges[i][0]) == find_parent(edges[i][1])){   //If parents of these nodes are same, means they already visited/connected, hence contributing in cycle.
                answer[0] = edges[i][0];
                answer[1] = edges[i][1];
                break;
            } else {
                do_union(edges[i][0] , edges[i][1]);
            }
        }
        return answer;
    }
};