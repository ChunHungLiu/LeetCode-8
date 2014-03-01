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
    TreeLinkNode* firstNodeWithChild(TreeLinkNode *root) {
        while (root && !root->left && !root->right) root = root->next;
        if (root) {
            return root->left ? root->left : root->right;
        }
        return NULL;
    }

    void connect(TreeLinkNode *root) {
        if (!root) { return; }
        TreeLinkNode* last = NULL;
        TreeLinkNode* cur = root;
        while (cur) {
            if (cur->left && cur->right) { cur->left->next = cur->right; }
            if (last) {
                if (cur->left) { last->next = cur->left; }
                else if (cur->right) { last->next = cur->right; }
            }
            if (cur->right) { last = cur->right; }
            else if (cur->left) { last = cur->left; }
            cur = cur->next;
        }        
        
        connect(firstNodeWithChild(root));
    }
};