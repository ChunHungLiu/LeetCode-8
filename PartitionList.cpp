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
    ListNode *partition(ListNode *head, int x) {
        ListNode* left = NULL, *left_cur = NULL;
        ListNode* right = NULL, *right_cur = NULL;
        
        while(head) {
            if (head->val < x) {
                if (!left) {
                    left = head; left_cur = head;
                } else {
                    left_cur->next = head;
                    left_cur = head;
                }
            } else {
                if (!right) {
                    right = head; right_cur = head;
                } else {
                    right_cur->next = head;
                    right_cur = head;
                }
            }
            head = head->next;
        }
        
        if (!left) { return right; }
        else { 
            left_cur->next = right;
            if (right_cur) { right_cur->next = NULL; }
            return left;
        }
    }
};