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
    int sumNumbers(TreeNode *root) {
        if (!root) { return 0; }
        
        int sum = 0, val = root->val;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre = NULL;
        
        while (!s.empty()) {
            TreeNode* cur = s.top();
            if (!pre || pre->left == cur || pre->right == cur) {
                if (cur->left) { s.push(cur->left); }
                else if (cur->right) { s.push(cur->right); }
                if (cur->left) { val *= 10; val += cur->left->val; }
                else if (cur->right) { val *= 10; val += cur->right->val; }
            } else if (cur->left == pre) {
                if (cur->right) { s.push(cur->right); }
                if (cur->right) { val *= 10; val += cur->right->val; } 
            } else {
                if (!cur->left && !cur->right) { sum += val; }
                val /= 10; s.pop();
            }
            pre = cur;
        }
        
        return sum;
    }
};