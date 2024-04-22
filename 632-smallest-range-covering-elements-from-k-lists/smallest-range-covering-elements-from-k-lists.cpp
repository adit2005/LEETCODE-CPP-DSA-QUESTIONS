class Solution {
public:
    class node {
        public:
        int data, row, col;
        node(int d, int r, int c):data(d),row(r),col(c){}
    };

    struct compare {
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*,vector<node*>, compare> minHeap;
        int mini = INT_MAX, maxi = INT_MIN;
        //maintain max while processing first element of each array
        for (int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i][0]);
            minHeap.push(new node(nums[i][0],i,0));
        }
        mini = minHeap.top()->data;
        int start = mini, end = maxi;
        //process all the remaining element by increasing mini

        while(!minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();
            //assign mini
            mini = temp->data;
            //update range
            if (maxi-mini < end-start){
                start = mini, end = maxi;
            }
            int row = temp->row, col = temp->col;
            //add next element infront of mini if within array
            if (col+1 < nums[row].size()){
                minHeap.push(new node(nums[row][col+1],row, col+1));
                maxi = max(maxi, nums[row][col+1]);
            }
            else //one of the array is fully traveresed!!
                break;
        }
        return {start,end};
    }
};