class Solution {
public:
    std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges) {
        // Create adjacency list to represent the graph
        vector<vector<int>> adjacencyList(n);

        // Array to track the indegree (number of incoming edges) of each node
        vector<int> indegree(n, 0);

        // Fill the adjacency list and indegree array based on the edges
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
            indegree[to]++;
        }

        // Queue to store nodes with zero indegree
        queue<int> nodesWithZeroIndegree;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                nodesWithZeroIndegree.push(i);
            }
        }

        // List to store the topological order of nodes
        std::vector<int> topologicalOrder;
        while (!nodesWithZeroIndegree.empty()) {
            int currentNode = nodesWithZeroIndegree.front();
            nodesWithZeroIndegree.pop();
            topologicalOrder.push_back(currentNode);

            // Reduce indegree of neighboring nodes and add them to the queue
            // if they have no more incoming edges
            for (int neighbor : adjacencyList[currentNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    nodesWithZeroIndegree.push(neighbor);
                }
            }
        }

        // Initialize the result list and set list for storing ancestors
        std::vector<std::vector<int>> ancestorsList(n);
        std::vector<std::unordered_set<int>> ancestorsSetList(n);

        // Fill the set list with ancestors using the topological order
        for (int node : topologicalOrder) {
            for (int neighbor : adjacencyList[node]) {
                // Add immediate parent
                ancestorsSetList[neighbor].insert(node);
                // Add all ancestors of the current node
                ancestorsSetList[neighbor].insert(
                    ancestorsSetList[node].begin(),
                    ancestorsSetList[node].end());
            }
        }

        // Convert sets to lists and sort them
        for (int i = 0; i < ancestorsList.size(); i++) {
            for (int node = 0; node < n; node++) {
                if (node == i) continue;
                if (ancestorsSetList[i].find(node) != ancestorsSetList[i].end()) {
                    ancestorsList[i].push_back(node);
                }
            }
            
        }

        return ancestorsList;
    }
};
