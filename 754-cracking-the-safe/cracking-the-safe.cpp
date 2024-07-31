class Solution {
public:
    // The dfs function performs a depth-first search to explore all possible password combinations
    bool dfs(int n, int k, string& ans, unordered_set<string>& visited) {
        // base case: all possible password combinations have been found (k^n combinations)
        if(visited.size() == pow(k, n))
            return true;
        
        // take the last n-1 characters of the current answer string
        string suffix = ans.substr(ans.size() - (n-1), n-1);
        
        // with this suffix (password of length n-1), try adding each of the k characters
        // at the end to form new nodes and perform dfs from there
        // adding a dummy character at the end to iterate over all k characters
        string nextNode = suffix + '0';
        for(int i = 0; i < k; i++) {
            nextNode[n-1] = (i + '0'); // replace the last character with the current character
                
            if(!visited.count(nextNode)) { // if this new node (password) hasn't been visited
                visited.insert(nextNode);  // mark it as visited
                ans += (i + '0');          // append the current character to the answer string
                
                // recursively perform dfs with the updated answer string
                if(dfs(n, k, ans, visited))
                    return true; // if a Hamiltonian path is found, return true

                // backtrack: remove the current character and mark the node as unvisited
                visited.erase(nextNode);
                ans.pop_back();
            }
        }
        
        return false; // if no Hamiltonian path is found from this node, return false
    }
    
    // This function initiates the process of finding the shortest string that contains all passwords
    string crackSafe(int n, int k) {
        unordered_set<string> visited; // to keep track of visited password combinations
        string ans = string(n, '0');   // start with the initial password of n zeros
        visited.insert(ans);           // mark the initial password as visited
        
        dfs(n, k, ans, visited);       // start the dfs process to find the shortest string
        return ans;                    // return the resulting shortest string
    }
};
