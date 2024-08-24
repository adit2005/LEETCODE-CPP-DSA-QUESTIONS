/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int ans = 0;
    
    // This is a depth-first search (DFS) function to traverse the employees' hierarchy.
    void dfs(vector<Employee*> employees, int node, vector<int>& vis, map<int,int> indx) {
        // Mark the current employee as visited
        vis[node] = 1;
        
        // Add the current employee's importance to the total sum
        ans += employees[node]->importance;
        
        // Get the list of subordinates for the current employee
        vector<int> adj = employees[node]->subordinates;
        
        // Recur for each subordinate (if not already visited)
        for (auto it : adj) {
            if (!vis[indx[it]]) {
                dfs(employees, indx[it], vis, indx);
            }
        }
        return;
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        // Initialize a visited array to keep track of visited employees
        vector<int> vis(employees.size(), 0);
        
        // Create a map to quickly find the index of an employee by their id
        map<int, int> indx;
        for (int i = 0; i < employees.size(); i++) {
            indx[employees[i]->id] = i;
        }
        
        // Start the DFS traversal from the employee with the given id
        dfs(employees, indx[id], vis, indx);
        
        // Return the accumulated importance value
        return ans;
    }
};
