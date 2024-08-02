class Solution {
public:
    int lengthLongestPath(string str) {
        
        int maxi = 0; // Variable to store the maximum path length
        stack<pair<int,int>> st; // Stack to store (depth, path length) pairs
        int ind = 0; // Index to traverse the string
        int n = str.size(); // Size of the input string
        stringstream data(str); // String stream to process the input string line by line
        string temp; // Temporary variable to hold each line
        
        // Process each line separated by '\n'
        while(getline(data,temp,'\n')){
            int i = 0;
            // Count the number of '\t' to determine the depth
            while(temp[i] == '\t'){
                i++;
            }
            int num = i; // Depth of the current line
            
            // Remove entries from the stack until we find the correct parent directory
            while(!st.empty() and st.top().first >= num){
                st.pop();
            }
            
            int prev = 0; // Length of the path to the parent directory
            if(!st.empty()) prev = st.top().second + 1; // +1 for the '/' character
            
            int curr = temp.size() - num; // Length of the current file/directory name
            
            // Check if the current line is a file
            auto found = temp.find('.');
            if (found != string::npos){
                // If it's a file, update the maximum path length
                maxi = max(maxi, prev + curr);
            }
            
            // Push the current (depth, path length) to the stack
            st.push({num, prev + curr});
        }
        
        return maxi; // Return the maximum path length
    }
};

