class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL) { return head; }
        
        ListNode *preTail = NULL;
        ListNode *curTail = NULL;
        ListNode *pre = NULL;
        ListNode *cur = head;
        
        for (int i = 1; i <= n; i++) {  
            if (i == m-1) { preTail = cur; }
            else if (i == m) { curTail = cur; }
            
            if (i >= m) { 
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            } else {
                cur = cur->next; 
            }
        }
        
        if (preTail == NULL) { head = pre; }
        else { preTail->next = pre; }
        curTail->next = cur; 
        
        return head;
    }
};