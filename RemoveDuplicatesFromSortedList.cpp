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
        ListNode* first = head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        
        while (cur != NULL) {
            if (cur->val == first->val) {
                pre->next = cur->next;
            } else {
                pre = cur;
                first = cur;
            }
            cur = cur->next;
        }
        
        return head;
    }
};