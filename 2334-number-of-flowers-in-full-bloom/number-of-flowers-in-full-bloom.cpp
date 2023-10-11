class Solution {
public:
int get_start(vector<int>&nums , int people){
        int low = 0;
        int high = nums.size()-1;
        int start = -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]<=people){
                start = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return start+1;
}
int get_end(vector<int>&nums , int people){
        int low = 0;
        int high = nums.size()-1;
        int end = -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]<people){
                end = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return end+1;
}

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
   
        for (auto& ele : flowers)
            start.push_back(ele[0]), end.push_back(ele[1]);
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> ans;
        for (auto ppl : people) { 
            ans.push_back(get_start(start , ppl) - get_end(end , ppl));
        }   
        return ans;
    }
};