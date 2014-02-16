class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) { return NULL; }
        if (!l1) { return l2; }
        if (!l2) { return l1; }

        ListNode* res = NULL;
        ListNode* cur = NULL;
        
        while (l1 && l2) {
            ListNode* tmp;
            if (l1->val < l2->val) {
                tmp = l1; l1 = l1->next;
            } else {
                tmp = l2; l2 = l2->next;
            }
            if (!res) {
                res = tmp; cur = tmp;
            } else {
                cur->next = tmp;
                cur = cur->next;
            }
        }
        
        if (l1) { cur->next = l1; }
        if (l2) { cur->next = l2; }
        return res;
    }
};