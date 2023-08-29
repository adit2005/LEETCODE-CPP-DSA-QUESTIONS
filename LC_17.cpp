class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        unordered_map<char, string> mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        string currentCombination;
        backtrack(digits, 0, mapping, currentCombination, result);
        
        return result;
    }
    
    void backtrack(const string& digits, int index, const unordered_map<char, string>& mapping, string& currentCombination, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }
        
        char digit = digits[index];
        string letters = mapping.at(digit);
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, mapping, currentCombination, result);
            currentCombination.pop_back(); 
        }
    }
};
