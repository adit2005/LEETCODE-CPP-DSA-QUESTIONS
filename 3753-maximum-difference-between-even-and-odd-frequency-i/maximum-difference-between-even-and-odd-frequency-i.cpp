#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        sort(s.begin(), s.end());  // Step 1: Sort the string
        vector<int> freq;

        // Step 2: Count frequencies
        int n = s.size();
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            freq.push_back(j - i);
            i = j;
        }

        vector<int> oddFreq, evenFreq;

        // Step 3: Separate frequencies
        for (int f : freq) {
            if (f % 2 == 0) evenFreq.push_back(f);
            else oddFreq.push_back(f);
        }

        // Step 4: Calculate max difference
        return *max_element(oddFreq.begin(), oddFreq.end()) - *min_element(evenFreq.begin(), evenFreq.end());
    }
};
