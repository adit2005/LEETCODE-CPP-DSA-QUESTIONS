#include <stack>
#include <string>

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        string word = "";
        
        // Trim leading spaces
        int start = 0;
        while(start < n && s[start] == ' ') {
            start++;
        }
        
        // Trim trailing spaces
        int end = n - 1;
        while(end >= 0 && s[end] == ' ') {
            end--;
        }
        
        // Process the string
        for(int i = start; i <= end; i++) {
            if(s[i] == ' ') {
                if(!word.empty()) {
                    st.push(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        // Handle the last word
        if(!word.empty()) {
            st.push(word);
        }
        
        string ans = "";
        while(!st.empty()){
            string a  = st.top();
            ans += a + " ";
            st.pop();
        }
        // Remove the trailing space
        if(!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};
