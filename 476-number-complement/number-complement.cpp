class Solution {
public:
    int findComplement(int num) {
        int i = 0, ans = 0;
        
        // Loop through each bit of 'num' until it becomes 0
        while (num) {
            // Extract the last bit of 'num'
            int temp = num & 1;
            
            // If the extracted bit is 0, it should become 1 in the complement
            if (!temp)
                // Add the corresponding power of 2 to 'ans'
                ans += pow(2, i);
            
            // Right shift 'num' by 1 to process the next bit
            num = num >> 1;
            
            // Move to the next bit position
            i++;
        }
        
        // Return the computed complement
        return ans;
    }
};
