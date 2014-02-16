/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) { return; }
        
        queue<TreeLinkNode*> q[2];
        int cur = 0, nxt = 1;
        q[cur].push(root);
       
        while (!q[cur].empty()) {
            TreeLinkNode* tmp = q[cur].front(); q[cur].pop();
            if (tmp->left) { q[nxt].push(tmp->left); }
            if (tmp->right) { q[nxt].push(tmp->right); }
            
            if (!q[cur].empty()) { tmp->next = q[cur].front(); }
            else { swap(cur, nxt); }
        }
    }
};