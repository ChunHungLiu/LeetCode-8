/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) { return NULL; }
        RandomListNode* res = new RandomListNode(head->label);
        map<RandomListNode*, RandomListNode*> table;
        table[head] = res;
        
        RandomListNode* tmp = head->next, *pre = res;
        while (tmp) {
            RandomListNode* cur = new RandomListNode(tmp->label);
            pre->next = cur; pre = cur;
            table[tmp] = cur;
            tmp = tmp->next;
        }
        
        tmp = head; pre = res;
        while (tmp) {
            pre->random = table[tmp->random];
            tmp = tmp->next; pre = pre->next;
        }
        
        return res;
    }
};