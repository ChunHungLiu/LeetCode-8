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
    struct greater_ListNode {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* res = NULL;
        if (lists.size() == 0) { return res; }
        priority_queue<ListNode*, vector<ListNode *>, greater_ListNode > q;
        for (auto j : lists) { if (j) { q.push(j); } }
        
        ListNode* cur = NULL;
        while (!q.empty()) {
            if (!res) { res = q.top(); } 
            else { cur->next = q.top(); }
            cur = q.top(); q.pop();
            if (cur->next) { q.push(cur->next); }
        }
        
        return res;
    }
};