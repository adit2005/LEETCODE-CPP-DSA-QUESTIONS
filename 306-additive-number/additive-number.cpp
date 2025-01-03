class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size()/2; i++)
            for (int j = 1; j <= (num.size()-i)/2; j++)
                if(checkAdditive(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;
        
        return false;
    }
    
private:
    bool checkAdditive(const string& first, const string& second, const string& rem)
    {
        // Check if the first number is 0, this is not allowed
        if (first.size() > 1 && first[0] == '0' || second.size() > 1 && second[0] == '0')
            return false;
        
        // Convert each string to a long and add them, convert them back to string for comparison
        string sum = to_string(stol(first) + stol(second));
        
        int sumSize = sum.size();
        // If the sum == remainder, that means we hit the end of the string
        if (sum == rem)
            return true;
        // Else if remainder size is <= sum size OR the substring in remainder of the same size as sum != sum
        // We return false, since we can't go any further
        else if (rem.size() <= sumSize || rem.substr(0, sumSize) != sum)
            return false;
        
        // If we make it here we have a match, and we check the rest of the string
    
           return checkAdditive(second, sum, rem.substr(sumSize));
     
       
    }
};