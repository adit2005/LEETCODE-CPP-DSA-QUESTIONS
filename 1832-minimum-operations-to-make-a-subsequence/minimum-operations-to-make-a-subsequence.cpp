class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size(), ans = 0;
        map<int, int> map;
        for(int i=0;i<n;i++) map[target[i]] = i;

        vector<int> longSubsq;
        for(int num : arr) {
            if(map.find(num) == map.end()) continue;
            auto it = lower_bound(longSubsq.begin(), longSubsq.end(), map[num]);
            if(it == longSubsq.end())
                longSubsq.push_back(map[num]);
            else *it = map[num];
        }
        return target.size() - longSubsq.size();
    }
};
