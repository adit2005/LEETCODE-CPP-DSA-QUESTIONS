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
    ListNode* temp;
    Solution(ListNode* head) {
        temp = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res;
        ListNode* curr = temp;
       int size = 1;
        while(curr) {
            //choosing probability is 1/size (reservior sampling)
            if(rand()%size == size-1)
                res = curr->val;
            curr = curr->next;
            size++;
        }
        return res;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */