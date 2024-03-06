class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>freq; int cnt = 0 ; 
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freq[nums[i]] ++;
        }
        for(auto it : freq){
            if(it.second%3 == 0 ){
                cnt += it.second/3;
            }
           else if(it.second  == 1 ){
              //  cnt +=( it.second/3) + 1;
                return -1;
                break;
            }
            else{
                  cnt +=( it.second/3) + 1;
            }
                
            
        }
        return cnt;
    }
};