class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
       unordered_map<int, int>mp;
       for(int i = 0; i<row.size(); i++) mp[row[i]] = i;
       int count = 0;
       for(int i = 0; i<row.size(); i+=2){
           int first = row[i];
           int second = first ^ 1;
           if(row[i+1] != second){
               count++;
               int val = row[i+1];
               int x = mp[second];
               swap(row[i+1], row[x]);
               mp[second] = i+1;
               mp[val] = x;
           }
       } 
       return count;
    }
};