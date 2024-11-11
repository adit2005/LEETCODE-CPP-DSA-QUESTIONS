class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        // Store the sieve array.
        vector<int> sieve(maxElement + 1, 1);
        sieve[1] = 0;
        for (int i = 2; i <= sqrt(maxElement + 1); i++) {
            if (sieve[i] == 1) {
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = 0;
                }
            }
        }

        // Start by storing the currValue as 1, and the initial index as 0.
        int currValue = 1;
        int i = 0;
        while (i < nums.size()) {
            // Store the difference needed to make nums[i] equal to currValue.
            int difference = nums[i] - currValue;

            // If difference is less than 0, then nums[i] is already less than
            // currValue. Return false in this case.
            if (difference < 0) {
                return 0;
            }

            // If the difference is prime or zero, then nums[i] can be made
            // equal to currValue.
            if (sieve[difference] == 1 or difference == 0) {
                i++;
                currValue++;
            } else {
                // Otherwise, try for the next currValue.
                currValue++;
            }
        }
        return 1;
    }
};