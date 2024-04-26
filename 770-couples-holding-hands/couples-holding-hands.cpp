class Solution {
public:
    vector<int> parent;
    int find_set(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    bool make_union(int x, int y){
        int a = find_set(x);
        int b = find_set(y);
        if(a == b) return false;
        parent[b] = a;
        return true;
    }

    int minSwapsCouples(vector<int>& row) {
       int n = row.size();
       if(n == 0) return 0;
       parent.resize(n);
       for(int i = 0; i<n; i+=2){
           parent[row[i]] = row[i];
           parent[row[i+1]] = row[i];
       }
       int count = 0;
       for(int i = 0; i<n; i+=2){
           if(make_union(i, i+1)) count++;
       }
       return count;
    }
};