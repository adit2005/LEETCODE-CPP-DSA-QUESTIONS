unordered_map<string,bool>mp; // A map to store memoized results
int solve(int ind,int s1,int siz,vector<int>&v){    
    if(ind>=v.size()) // If index exceeds array size
        return s1==0&&siz==0; // Return true if target sum and size are zero
    if(siz==0) // If size is zero
        return s1==0; // Return true if target sum is zero
    
    string k=to_string(ind)+" "+to_string(s1)+" "+to_string(siz); // Create a unique key for the current state
    if(mp.find(k)!=mp.end()) // Check if result is already memoized
        return mp[k]; // Return the memoized result

    mp[k]=false; // Initialize the current state result to false
    if(v[ind]<=s1) // If the current element can be included in the subset
        mp[k]|=solve(ind+1,s1-v[ind],siz-1,v); // Include the element and solve for the remaining target sum and size
    if(mp[k]) // If including the element leads to a solution
        return 1; // Return true
    return mp[k]|=solve(ind+1,s1,siz,v); // Exclude the element and solve for the current target sum and size
}

class Solution {
public:    
    bool splitArraySameAverage(vector<int>& v) {        
        // Explanation for variables:
        // s1 + s2 = s (total sum)
        // n1 + n2 = n (total number of elements)
        // s1/n1 = s2/n2 --> s2 = (n-n1)*s1/n1
        // s1 = s*n1/n (target sum for subset)

        mp.clear(); // Clear the memoization map
        int s=0; // Initialize total sum
        for(auto i:v)
            s+=i; // Calculate the total sum of the array

        int n=v.size(); // Get the size of the array
        for(int i=1;i<n;++i) { // Iterate through possible sizes of subset
            if((s*i)%n==0) { // Check if the total sum * size of subset is divisible by the array size
                int s1=s*i; // Calculate the target sum for the subset
                s1/=n; 

                if(solve(0,s1,i,v)) // Solve for the subset with the target sum and size
                    return true; // Return true if a valid subset is found
            }
        }
        return false; // Return false if no valid subset is found
    }
};
