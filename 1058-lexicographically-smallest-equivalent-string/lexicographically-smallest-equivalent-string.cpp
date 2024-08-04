class Solution {
public:
    // Function for finding the representative (root) of a set
    int find(vector<int>& parent, int x) {
        // Base case: if x is its own parent, return x
        if (parent[x] == x) {
            return x;
        }
        
        // Recursively find the root and perform path compression
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }
    
    // Function for union of two elements
    void unionn(int x, int y, vector<int>& parent) {
        // Find the representatives (roots) of both x and y
        int rep_x = find(parent, x);
        int rep_y = find(parent, y);
        
        // If both elements are already in the same set, do nothing
        if (rep_x == rep_y) {
            return;
        }
        
        // Always make the lexicographically smaller element the representative
        if (rep_x < rep_y) {
            parent[rep_y] = rep_x;
        } else {
            parent[rep_x] = rep_y;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        
        // There are only 26 characters from 'a' to 'z'
        // Declare a parent array to represent each character
        vector<int> parent(26);
        
        // Initialize each character to be its own parent
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        
        // Union the characters from s1 and s2
        for (int i = 0; i < n; i++) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            unionn(x, y, parent);
        }
        
        // Form the lexicographically smallest result string
        string res = "";
        for (int i = 0; i < baseStr.size(); i++) {
            int rep = find(parent, baseStr[i] - 'a');
            res += 'a' + rep;
        }
        
        return res;
    }
};
