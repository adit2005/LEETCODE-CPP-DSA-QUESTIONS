class Solution {
public:
    vector<vector<int>>dp;
    int maxTurbulenceSize(vector<int>& arr) {
         dp.resize(arr.size(),vector<int>(2,-1));
         int ans = 0;
         for(int i = 0 ; i < arr.size() ; i++){
              //int choise1 = longest subarray we can have of the nature bg sml bg sml
              //int choise2 = longesy subarray we can have of the nature sml bg
              int choise1 = 1 + fun(i+1,arr,true);   //next should be big
              int choise2 = 1 + fun(i+1,arr,false);  //next should be small
              ans = max(ans , max(choise1,choise2));
         }
         return ans;
    }
    int fun(int idx , vector<int>&arr , bool flag){
          if(idx >= arr.size()){
             return 0;
          }
          if(dp[idx][flag] != -1){
            return dp[idx][flag];
          }
          if(flag == true){
               if(arr[idx-1] < arr[idx]){
                   return dp[idx][flag] = 1 + fun(idx+1,arr,false);
               }   
               else return dp[idx][flag] = 0;
          }
          else if(flag == false){
               if(arr[idx-1] > arr[idx]){
                   return dp[idx][flag] = 1 + fun(idx+1,arr,true);
               }
               else return dp[idx][flag] = 0;
          }
          return -1;
    }
};