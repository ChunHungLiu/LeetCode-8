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
    void flatten(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* pre = NULL;

        while (cur || !s.empty()) {
            if (cur) {
                if (pre) { pre->left = NULL; pre->right = cur; }
                pre = cur;

                if (cur->right) s.push(cur->right);
                cur = cur->left;
            } else {
                cur = s.top(); s.pop();
            }
        }
    }
};