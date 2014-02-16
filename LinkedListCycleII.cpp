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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (slow && fast) {
            if (!slow->next) { return NULL; }
            if (!fast->next || !fast->next->next) { return NULL; }
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                fast = head;
                while (fast != slow) {
                    slow = slow->next; 
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* cur = head;
        unordered_set<ListNode*> table;
        
        while (cur) {
            if (table.find(cur) != table.end()) {
                return cur;
            }
            table.insert(cur);
            cur = cur->next;
        }

        return NULL;
    }
};