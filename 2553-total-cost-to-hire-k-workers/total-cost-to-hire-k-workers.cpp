class Solution {
public:
    long long totalCost(vector<int>& nums, int k, int cand) {
        long long ans = 0;
        priority_queue<pair<int,pair<int,char>>, vector<pair<int,pair<int,char>>>, greater<pair<int,pair<int,char>>>> pq;
        
        int left = 0;
        int right = nums.size()-1;
        
        for(int i=0;i<cand;i++)
        {
            pq.push({nums[left],{left,'L'}});
            left++;
        }
        
        for(int i=0;i<cand && left <= right;i++)
        {
            pq.push({nums[right],{right,'R'}});
            right--;
        }
        while(k-- && !pq.empty())
        {
            auto pat = pq.top();
            pq.pop();
            
            char x = pat.second.second;
            ans += pat.first;
            
            if(left <= right)
            {
                if(x == 'L')
                {
                    pq.push({nums[left],{left,'L'}});
                    left++;
                }
                else
                {
                    pq.push({nums[right],{right,'R'}});
                    right--;
                }
            }
        }
        return ans;
    }
};