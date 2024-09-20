class Solution {
public:
    
    struct node{
        int pos;
        float time;
    };
    
    static bool compare(struct node &a, struct node &b){
        if(a.pos == b.pos) return a.time > b.time;
        return a.pos < b.pos;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        
        vector<node> fleet;
        for(int i=0;i<n;i++){
            fleet.push_back({position[i], (target-position[i])/(float)speed[i]});
        }
        
        sort(fleet.begin(),fleet.end(),compare);
        
        int c=0;
        int i=n-1;
        while(i>=0){
            c++;
            float t=fleet[i].time;
            while(--i>=0 && fleet[i].time <= t) continue; // cars part of same fleet 
        }
        
        return c;
    }
};