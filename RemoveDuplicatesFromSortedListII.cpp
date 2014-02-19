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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) { return head; }
        while (head && head->next && head->val == head->next->val) {
            while (head->next && head->val == head->next->val) { head = head->next; }
            head = head->next;
        }
        if (!head || !head->next) { return head; }

        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nxt = head->next->next;
        
        while (nxt) {
            if (cur->val != nxt->val) {
                if (pre->next == cur) {
                    pre = cur;
                } else {
                    pre->next = nxt;
                }
            }
            cur = nxt;
            nxt = nxt->next;
        }
        
        if (pre->next != cur) {
            pre->next = NULL;
        }
        
        return head;
    }
};