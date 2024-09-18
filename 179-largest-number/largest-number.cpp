class Solution {
public:
    
   // Static comparison function for sorting strings
   static bool comp(string &s1 , string &s2){
        return (s1 + s2) > (s2 + s1);
   }
   
   // Function to find the largest number from a vector of integers
   string largestNumber(vector<int>& nums) {
        int n = nums.size();
        
        // If there is only one element in the vector, return it as a string
        if (n == 1)
            return to_string(nums[0]);
        
        int count = 0;
        
        // Count the number of zeros in the vector
        for (int x : nums)
            if (x == 0)
                count++;
        
        // If all elements are zeros, return "0" since it's the largest possible number
        if (count == n)
            return "0";
        
        // Convert integers to strings and store them in a vector of strings
        vector<string> s(n, "");
        for (int i = 0; i < n; i++)
            s[i] = to_string(nums[i]);
        
        // Sort the strings in descending order using the custom comparison function
        sort(s.begin(), s.end(), comp);
        
        // Concatenate the sorted strings to form the final result
        string ans = "";
        for (int i = 0; i < n; i++)
            ans += s[i];
        
        return ans;
    }
};
