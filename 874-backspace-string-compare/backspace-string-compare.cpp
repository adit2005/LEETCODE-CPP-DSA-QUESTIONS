class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        stack<int>st1;
        stack<int>st2;
        for(int i=0; i<n1; i++){
            if(s[i]=='#'){
                if(!st1.empty()){
                    st1.pop();
                }      
            }else{
                st1.push(s[i]);
            }
        }
        for(int i=0; i<n2; i++){
            if(t[i]=='#'){
                if(!st2.empty()){
                    st2.pop();
                }  
            }else{
                st2.push(t[i]);
            }
        }
        s.clear(); t.clear();
        while(!st1.empty()){
            s+=st1.top();
            st1.pop();
        }
        while(!st2.empty()){
            t+=st2.top();
            st2.pop();
        }
        if(s==t)return true;
        return false;
    }
};