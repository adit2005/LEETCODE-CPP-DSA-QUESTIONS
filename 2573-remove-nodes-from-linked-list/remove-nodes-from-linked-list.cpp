/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* current = head;

        // Add nodes to the stack
        while (current != nullptr) {
            stack.push(current);
            current = current->next;
        }

        current = stack.top();
        stack.pop();
        int maximum = current->val;
        ListNode* resultList = new ListNode(maximum);

        // Remove nodes from the stack and add to result
        while (!stack.empty()) {
            current = stack.top();
            stack.pop();
            // Current should not be added to the result
            if (current->val < maximum) {
                continue;
            }
            // Add new node with current's value to front of the result
            else {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultList;
                resultList = newNode;
                maximum = current->val;
            }
        }

        return resultList;
    }
};