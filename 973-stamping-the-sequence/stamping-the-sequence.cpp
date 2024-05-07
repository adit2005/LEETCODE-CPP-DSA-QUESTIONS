class Solution {
public:
    // Function to check if stamp can be placed at index i in target string
    bool isequal(int i, string s, string t) {
    for (int j = 0; j < s.size(); j++) {
        if (t[j+i] != '?' && t[j+i] != s[j])
            return false;
    }
    return true;
}

    
    // Function to replace characters in target string with '?' starting from index i
    int replace(int i, string &t, int n){
        int ct = 0;
        // Iterate through characters in target starting from index i
        for(int j = 0; j < n; j++){
            // If character is not '?', replace it with '?' and increment count
            if(t[i + j] != '?'){
                t[i + j] = '?';
                ct++;
            }
        }
        return ct; // Return count of replaced characters
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int n = stamp.size(), m = target.size();
        vector<int> ans, vis(m); // Initialize result vector and visited array
        
        int count = 0; // Initialize count of replaced characters
        
        // Iterate until entire target string is transformed
        while(count != m){
            bool flag = true; // Flag to check if stamp can be placed
            
            // Iterate through target string
            for(int i = 0; i <= m - n; i++){
                // Check if stamp can be placed at index i
                if(!vis[i] && isequal(i, stamp, target)){
                    ans.push_back(i); // Add starting index to result
                    count += replace(i, target, n); // Replace characters with '?'
                    vis[i] = 1; // Mark visited positions
                    flag = false; // Set flag to false indicating stamp placement
                }
                // Break if entire target string is transformed
                if(count == m) 
                    break;
            }
            
            // If stamp can't be placed in any position, return empty vector
            if(flag) 
                return {};
        }
        
        // Reverse the result vector and return
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
