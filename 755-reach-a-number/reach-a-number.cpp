class Solution {
public:
    int reachNumber(int target) {
    if(target<0){
    target=-target;
  }
    int step=0;
    int sum=0;
    while(true)
    {
        step++;
        sum=sum+step;
        if(sum==target)
        {
            return step;
        }
        else if(sum>target && (sum-target)%2==0)
        {
            return step;
        }
    }
}
};