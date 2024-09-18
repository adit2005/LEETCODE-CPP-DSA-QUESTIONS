class Solution {
public:
    
    // function for finding double using binary search
    
    int search(vector<int>& arr, int low, int high, vector<bool>& vis, int x)
    {
        int ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] == x && vis[mid] == false)
            {
                ans = mid;
                
                high = mid - 1;
            }
            else if(arr[mid] == x && vis[mid] == true)
            {
                low = mid + 1;
            }
            else if(arr[mid] < x)
            {
                low = mid + 1;
            }
            else if(arr[mid] > x)
            {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    vector<int> findOriginalArray(vector<int>& arr) {
        
        int n = arr.size();
        
        // if size of arr is odd then no res. possible
        
        if(n % 2)
            return {};
        
        // sort the array
        
        sort(arr.begin(), arr.end());
        
        // declare a vis array, initialize with false
        
        vector<bool> vis(n, false);
        
        // res will store the elements of original array
        
        vector<int> res;
        
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == false)
            {
                // find the index of doubled element in arr
                
                int idx = search(arr, i + 1, n - 1, vis, 2 * arr[i]);
                
                // if double element is found, then mark single and double element as found
                
                // push the single element into res
                
                if(idx != -1)
                {
                    vis[i] = true;
                
                    vis[idx] = true;
                
                    res.push_back(arr[i]);
                }
                
                // if double element is not found in array, then return empty array
                
                else if(idx == -1)
                {
                    return {};
                }
            }
        }
        
        return res;
    }
};