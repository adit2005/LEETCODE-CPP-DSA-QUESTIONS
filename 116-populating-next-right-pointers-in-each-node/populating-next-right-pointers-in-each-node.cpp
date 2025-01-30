/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        auto L = root->left, R = root->right, N = root->next;
        if (L) {
            L->next = R; // next of root's left is assigned as root's right
            if (N){
                 R->next = N->left; 
            }
            else{
                R->next = nullptr;
            }
              
            connect(L);            
            connect(R);            
        }
        return root;
    }
};