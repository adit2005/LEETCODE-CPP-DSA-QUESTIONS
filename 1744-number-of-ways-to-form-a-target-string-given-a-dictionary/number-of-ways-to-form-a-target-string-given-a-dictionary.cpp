class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        // Step 1: Calculate frequency of each character at every index in
        // "words".
        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Step 2: Initialize two DP arrays: prev and curr.
        vector<long> prevCount(targetLength + 1, 0);
        vector<long> currCount(targetLength + 1, 0);

        // Base case: There is one way to form an empty target string.
        prevCount[0] = 1;

        // Step 3: Fill the DP arrays.
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            // Copy the previous row into the current row for DP.
            currCount = prevCount;
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                // If characters match, add the number of ways.
                int curPos = target[currTarget - 1] - 'a';
                currCount[currTarget] += (charFrequency[currWord - 1][curPos] *
                                          prevCount[currTarget - 1]) %
                                         MOD;
                currCount[currTarget] %= MOD;
            }
            // Move current row to previous row for the next iteration.
            prevCount = currCount;
        }

        // Step 4: The result is in prev[targetLength].
        return currCount[targetLength];
    }
};