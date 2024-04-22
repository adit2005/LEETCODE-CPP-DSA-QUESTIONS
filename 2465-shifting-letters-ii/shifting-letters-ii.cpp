class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        long sz=s.size();
        vector<long>line(sz+1,0);
        for(auto & i:sh){
            // forward shift so do +1
            if(i[2]==1){
                line[i[0]]++;
                line[i[1]+1]--;
            }
            //backward shift so do -1
            else{
                line[i[0]]--;
                line[i[1]+1]++;                
            }
        }
        for(int i=1;i<=sz;i++)
            line[i]+=line[i-1];
        for(int i=0;i<sz;i++){
		// line[i] is how many times i have to increase or decrease the s[i] char.So i am adding it and taking modulo
			int increaseBy=(s[i]-'a'+line[i])%26;
		// this is to make -ve module +ve. 
			increaseBy=(increaseBy+26)%26;
			s[i]='a'+increaseBy;
        }
        return s;      
    }
};