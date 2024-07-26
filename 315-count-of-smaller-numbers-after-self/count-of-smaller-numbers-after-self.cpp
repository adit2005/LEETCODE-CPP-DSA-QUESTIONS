class BIT {
private:
    vector<int> bit;
    int n;

public:
    BIT(int size = 20001) { // Default size to handle range [-10^4, 10^4] shifted to [0, 2*10^4]
        n = size;
        bit.assign(n, 0);
    }

    // Update the BIT with the given value at the given index
    void update(int idx, int val) {
        while (idx < n) {
            bit[idx] += val; // Add val to the current index
            idx = idx | (idx + 1); // Move to the next index that needs to be updated
        }
    }

    // Query the sum of values up to the given index
    int query(int idx) {
        int s = 0; // Initialize sum
        while (idx >= 0) {
            s += bit[idx]; // Add the value at the current index to the sum
            idx = (idx & (idx + 1)) - 1; // Move to the next index to sum
        }
        return s; // Return the total sum
    }

    // Convert an index to the BIT index
    int getidx(int idx) {
        return idx + 10000; // Shift the index by 10^4 to handle negative values
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans; // Vector to store the result
        BIT bit; // Initialize the BIT

        // Update the BIT with the frequencies of each element in the array
        for (int i : nums) {
            bit.update(bit.getidx(i), 1);
        }

        // For each element in the array, count the number of smaller elements to the right
        for (int i : nums) {
            // Query the BIT to get the count of elements smaller than the current element
            ans.push_back(bit.query(bit.getidx(i - 1)));
            // Update the BIT to remove the current element (as it has been processed)
            bit.update(bit.getidx(i), -1);
        }

        return ans; // Return the result
    }
};
