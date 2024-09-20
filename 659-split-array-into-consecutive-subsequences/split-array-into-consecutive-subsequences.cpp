class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // 'freq' will store the frequency of each number in the input array 'nums'.
        map<int,int> freq;
        
        // Step 1: Populate the frequency map with counts of each number.
        for (int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        // 'extra' will store the count of subsequences ending with a particular number.
        // This helps us in extending existing subsequences if possible.
        map<int,int> extra;

        // Step 2: Iterate through each number in the array 'nums'.
        for (int i = 0; i < nums.size(); i++){
            // If the current number's frequency is 0, it means it has already been used in subsequences, so we skip it.
            if (freq[nums[i]] == 0) continue;

            // Decrease the frequency of the current number because we are about to use it in a subsequence.
            freq[nums[i]]--;

            // Step 3: Check if we can extend a subsequence that ends at nums[i] - 1.
            // If there's a subsequence ending at nums[i]-1, extend it by adding nums[i] to it.
            if (extra[nums[i] - 1] > 0) {
                // Reduce the count of subsequences ending at nums[i]-1.
                extra[nums[i] - 1]--;
                // Now, we have a subsequence that ends at nums[i].
                extra[nums[i]]++;
            }
            // Step 4: If we can't extend an existing subsequence, we try to start a new subsequence with nums[i].
            // To start a new subsequence, we need nums[i], nums[i]+1, and nums[i]+2 available.
            else if (freq[nums[i] + 1] > 0 && freq[nums[i] + 2] > 0) {
                // Reduce the frequencies of nums[i]+1 and nums[i]+2 as they will be part of the new subsequence.
                freq[nums[i] + 1]--;
                freq[nums[i] + 2]--;
                // The new subsequence now ends at nums[i]+2, so update the 'extra' map.
                extra[nums[i] + 2]++;
            }
            // Step 5: If neither extending an existing subsequence nor starting a new valid subsequence is possible, return false.
            else return false;
        }

        // Step 6: If we've processed all numbers without issues, return true, meaning it's possible to form valid subsequences.
        return true;
    }
};
