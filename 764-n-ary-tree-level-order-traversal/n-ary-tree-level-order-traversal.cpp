/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty()) {
            size_t size = Q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* curr = Q.front(); Q.pop();
                level.push_back(curr->val);
                for (Node*& child: curr->children) {
                    Q.push(child);
                }
            }
            result.push_back(level);
        }

        return result;
    }
};