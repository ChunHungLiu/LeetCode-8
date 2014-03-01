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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k < 2) { return head; }
        
        ListNode* cur = head;
        int len = 0;
        while (cur) { ++len; cur = cur->next; }
        if (k > len) { return head; }
        
        ListNode *preTail = NULL, *curTail = NULL, *curHead = NULL, *pre = NULL;
        
        cur = head; 
        
        for (int i = 0; i < len/k; ++i) {
            pre = NULL;
            for (int j = 0; j < k; ++j) {
                if (j == 0) curTail = cur;
                if (j == k-1) curHead = cur;
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            
            if (!preTail) { head = curHead; }
            else { preTail->next = curHead; }
            
            preTail = curTail;
        }
        
        curTail->next = cur;
        
        return head;
    }
};