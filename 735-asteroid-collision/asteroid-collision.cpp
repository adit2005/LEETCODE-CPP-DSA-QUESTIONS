class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>v;
        stack<int>s;

        for(auto x: asteroids){
            if(x > 0) s.push(x);
            else{

                while(s.size() >0 && s.top() > 0 && s.top() < abs(-x)){
                    s.pop();
                }
                if(s.size() > 0 && s.top() == abs(-x)){
                    s.pop();

                }
                  else if( s.size() > 0 && s.top() > abs(-x) ){
                  
                }
                 else{
                    s.push(x);
                }
            }
        }

        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        
        reverse(v.begin(),v.end());
        
        return v;
    }
};