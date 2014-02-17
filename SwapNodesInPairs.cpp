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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) { return head; }
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        
        while (nxt) {
            cur->next = nxt->next;
            nxt->next = cur;
            if (pre) { pre->next = nxt; }
            else { head = nxt; }
            pre = cur;
            cur = pre->next;
            nxt = cur ? cur->next : NULL;
        }
        
        return head;
    }
};