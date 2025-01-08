class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
      int cnt = 0;
       for(int i = 0; i<words.size();i++){
           int s = words[i].size();
           for(int j = i+1; j < words.size();j++){
               if(words[j].size()>=s){
                   if((words[j].substr(0,s) == words[i])  && (words[j].substr(words[j].size()-s,s) == words[i]) ) cnt++;
                
                                                                                                          
               }
             
           }
       }
        return cnt;
    }
};