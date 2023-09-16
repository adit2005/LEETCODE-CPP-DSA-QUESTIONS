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
    // Custom comparator class for the priority queue
    class MyCmp {
    public:
        bool operator()(ListNode *l1, ListNode *l2) {
            // Comparison function to determine the priority in the priority queue
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = lists.size();
        
        // Create a min-heap (priority queue) with custom comparator MyCmp
        priority_queue<ListNode*, vector<ListNode*>, MyCmp> pq;
        
        // Push the heads of all input linked lists into the min-heap if they are not NULL
        for (int i = 0; i < l; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        
        // Create a dummy head for the merged linked list
        ListNode *head = new ListNode();
        ListNode *curr = head;
        
        // While the min-heap is not empty
        while (!pq.empty()) {
            // Get the node with the smallest value from the min-heap
            curr->next = pq.top();
            curr = curr->next;
            pq.pop();
            
            // If there is a next node in the selected linked list, push it into the min-heap
            if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }
        
        // Return the merged linked list starting from the next node of the dummy head
        return head->next;
    }
};
