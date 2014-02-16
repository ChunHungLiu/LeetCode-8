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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (slow && fast) {
            if (!slow->next) return false;
            if (!fast->next || !fast->next->next) return false;
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        
        return false;
    }
};