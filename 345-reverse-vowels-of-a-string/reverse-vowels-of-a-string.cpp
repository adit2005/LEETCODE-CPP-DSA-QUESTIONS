class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st = {'a','A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        int i=0, j=s.length()-1;
        while(i<j){
            while(!st.count(s[i]) && i<j){
                i++;
            }
            while(!st.count(s[j]) && i<j) j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};