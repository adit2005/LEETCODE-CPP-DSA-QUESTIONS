class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(),nums.end());    
        unordered_map<long long,long long>m;
        for(int x: nums)m[x]++;

        long long ans = 1;
        if(m.find(1)!=m.end()){                    
            long long freq =m[1];                  
            if(freq % 2 == 0)freq--; 
                                       
            ans = freq;             
        }

        for(long long i : nums)
        {
            long long currans = 0;  
            while(i != 1 && m.find(i)!=m.end() && m[i] >= 2){
                currans+=2;                        
                                                  
                m.erase(i);              
                i = i*i;          
            }

            if(m.find(i)!=m.end()){
                currans++;              
            }
            else{
                currans--;     
            }
            ans = max(ans,currans);
        }
        return ans;
    }
};