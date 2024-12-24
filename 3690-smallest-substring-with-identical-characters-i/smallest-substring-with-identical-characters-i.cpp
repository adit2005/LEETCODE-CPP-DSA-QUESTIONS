class Solution {
public:
    bool check(string& s, int numOps, int mid, char startChar){
    for(int i = 0; i < s.size(); ++i){
        if(startChar == s[i]) numOps--;
        startChar = (startChar == '0')?'1':'0';
    }
    return (numOps >= 0);
}

    bool isValid(string& s, int numOps, int mid){
        if(mid == 1) return check(s, numOps, mid, '1') || check(s, numOps, mid, '0');
        int count = 0;
        for(int i = 0, last = -1; i < s.size(); ++i){
            if(s[i] == last) count++; 
            else{
                numOps -= count/(mid+1);
                last = s[i];
                count = 1;
            }
        }
        if(count > mid) numOps -= count/(mid+1);
        return (numOps >= 0);
    }

    int minLength(string s, int numOps) {
        int start = 1, end = s.size(), mid, ans = s.size();
        while(start <= end){
            mid = start + (end - start)/2;
            if(isValid(s, numOps, mid)){
                ans = mid;
                end = mid - 1;
            }else start = mid + 1;
        }
        return ans;
    }
};