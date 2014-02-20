/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) { return false; }
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre = NULL;
        sum -= root->val;
        
        while (!s.empty()) {
            TreeNode* cur = s.top();
            if (!pre || pre->left == cur || pre->right == cur) {
                if (cur->left) { s.push(cur->left); sum -= cur->left->val; }
                else if (cur->right) { s.push(cur->right); sum -= cur->right->val; }
                else if (sum == 0) { return true; }
            } else if (cur->left == pre) {
                if (cur->right) { s.push(cur->right); sum -= cur->right->val; }
            } else {
                sum += cur->val;
                s.pop();
            }
            pre = cur;
        }
        
        return false;
    }
};