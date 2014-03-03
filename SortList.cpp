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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) { return head; }
        
        ListNode *first = head, *second = head->next;
        while (second && second->next) {
            first = first->next;
            second = second->next->next;
        }
        
        ListNode *h2 = sortList(first->next);
        first->next = NULL;
        return merge(sortList(head), h2);
    }
    
    ListNode *merge(ListNode *h1, ListNode *h2) {
        ListNode *res = NULL, *cur = NULL;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                if (!res) { res = h1; cur = h1; }
                else { cur->next = h1; cur = h1; }
                h1 = h1->next;
            } else {
                if (!res) { res = h2; cur = h2; }
                else { cur->next = h2; cur = h2; }
                h2 = h2->next;
            }
        }
        
        if (h1) { cur->next = h1; }
        if (h2) { cur->next = h2; }
        
        return res;
    }
};