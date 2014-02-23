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
    ListNode *insertionSortList(ListNode *head) {
        ListNode* res = NULL;
        
        while (head) {
            ListNode* tmp = head;
            head = head->next; tmp->next = NULL;
            
            if (!res) { res = tmp; }
            else if (tmp->val < res->val) { tmp->next = res; res = tmp; }
            else {
                ListNode* cur = res;
                while (cur->next) {
                    if (tmp->val < cur->next->val) { 
                        tmp->next = cur->next; 
                        cur->next = tmp; 
                        break;
                    }
                    cur = cur->next;
                }
                if (!cur->next) { cur->next = tmp; }
            }
        }
        
        return res;
    }
};