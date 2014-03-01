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
    ListNode* reverse(ListNode *head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        
        return pre;
    }

    void reorderList(ListNode *head) {
        if (!head || !head->next) { return; }
        
        ListNode *l1 = head, *l2 = head;
        
        while (l2 && l2->next) {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        
        l2 = l1->next;
        l1->next = NULL;
        l2 = reverse(l2);
        
        l1 = head;
        while (l1 && l2) {
            ListNode* tmp = l1->next;
            l1->next = l2;
            l1 = tmp;
            
            tmp = l2->next;
            l2->next = l1;
            l2 = tmp;
        }
    }
};