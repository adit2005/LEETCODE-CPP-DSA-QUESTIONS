#include <vector>
#include <map>

class Solution {
public:
    int reductionOperations(std::vector<int>& nums) {
        std::map<int, int> count;
        int operations = 0;

        // Count the frequency of each number
        for (int num : nums) {
            count[num]++;
        }

        int prevFreq = 0;
        for (auto it = count.rbegin(); it != count.rend(); ++it) {
            operations += prevFreq;
            prevFreq += it->second;
        }

        return operations;
    }
};