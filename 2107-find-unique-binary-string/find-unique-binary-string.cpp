class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;

        int index = 0;
        for(auto binary : nums)
        {
            ans = ans + to_string('1' - binary[index]);
            index+=1;
        }
        return ans;
    }
};