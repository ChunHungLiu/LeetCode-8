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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* res = NULL;
        ListNode* cur = res;
        
        int carry = 0, val = 0;
        while (l1 || l2) {
            if (l1 && l2) {
                val = l1->val + l2->val + carry;
                l1 = l1->next; l2 = l2->next;
            } else if (l1) {
                val = l1->val + carry;
                l1 = l1->next;
            } else {
                val = l2->val + carry;
                l2 = l2->next;
            }
            
            carry = val / 10; val %= 10;
            ListNode* tmp = new ListNode(val);
            if (!cur) { cur = tmp; res = tmp; }
            else { cur->next = tmp; cur = tmp; }
        }

        if (carry) {
            cur->next = new ListNode(carry);
        }
        
        return res;
    }
};