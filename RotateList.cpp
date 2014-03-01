/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) { return NULL; }
        if (k == 0) { return head; }
        
        // get length
        ListNode* first = head;
        int len = 0;
        first = head;
        while (first) { first = first->next; ++len; }
        
        // get rotation
        k = k%len;
        
        first = head; 
        while (first->next && k--) { first = first->next; }
        
        ListNode* second = head;
        while (first->next) { first = first->next; second = second->next; }
        
        first->next = head;
        head = second->next;
        second->next = NULL;
        
        return head;
    }
};