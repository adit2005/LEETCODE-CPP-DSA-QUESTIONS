class Solution {   
public:
  bool isVowel(char c){
        char t = tolower(c);
        return t == 'a' or t == 'e' or t=='i' or t=='o' or t=='u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int cnt = 0;
        int ans = 0;
        while(end < n){
           if(isVowel(s[end])){
               cnt++;
           }
           if(end - start +1 == k){
               ans = max(ans, cnt);
               if(isVowel(s[start])){
                   cnt--;
               }
                start++;
           }
            
             end++;

        }

        return ans;

    }    
    
    

};