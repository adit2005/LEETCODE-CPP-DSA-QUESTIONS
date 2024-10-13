class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //create a min heap (data, (row,col))
        priority_queue< pair<int,pair<int,int>> , 
                vector<pair<int,pair<int,int>>>,
               greater<pair<int,pair<int,int>>> >minHeap;

        int mini = INT_MAX, maxi = INT_MIN;

        //insert first element into minHeap 
        for(int i = 0; i < nums.size(); i++){
            minHeap.push({nums[i][0], {i,0}});
            maxi = max(maxi, nums[i][0]);
        }
        mini = minHeap.top().first;
        int start = mini, end = maxi;

        //process all elements, by inserting min->next into heap
        while(!minHeap.empty()){
            pair<int,pair<int,int>> top = minHeap.top();
            minHeap.pop();
            //update mini
            mini = top.first;
            //if smaller range found update range
            if (maxi-mini < end-start)
                start = mini, end = maxi;
            
            //if next element of mini present push it
            int row = top.second.first, col = top.second.second;
            if (col+1 < nums[row].size()){
                minHeap.push({nums[row][col+1],{row,col+1}});
                //update maxi after pushing new element
                maxi = max(maxi, nums[row][col+1]);
            }
            else
                break;
        }
        return {start,end};
    }
};